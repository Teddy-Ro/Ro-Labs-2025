// Term.h
#ifndef TERM_H
#define TERM_H

#include <iostream>
#include <cctype>
#include <stdexcept>

class Term {
private:
    int coefficient;
    int exponent;

    // Парсинг терма из потока
    void parseTerm(std::istream& is) {
        coefficient = 0;
        exponent = 0;
        int sign = 1;

        // Пропуск пробелов
        while (is.peek() == ' ') is.get();

        // Обработка знака
        if (is.peek() == '-') {
            sign = -1;
            is.get();
        } else if (is.peek() == '+') {
            is.get();
        }

        while (is.peek() == ' ') is.get();

        // Чтение коэффициента
        if (isdigit(is.peek())) {
            is >> coefficient;
            coefficient *= sign;
        } else {
            coefficient = sign * 1; // Например, "x" → 1x^1
        }

        // Пропуск пробелов
        while (is.peek() == ' ') is.get();

        // Обработка переменной 'x'
        if (is.peek() == 'x') {
            is.get();
            exponent = 1;

            // Пропуск пробелов
            while (is.peek() == ' ') is.get();

            // Обработка степени (если есть '^')
            if (is.peek() == '^') {
                is.get();
                is >> exponent;
            }
        }
    }

public:
    Term(int coeff = 0, int exp = 0) : coefficient(coeff), exponent(exp) {}

    int getCoefficient() const { return coefficient; }
    int getExponent() const { return exponent; }

    Term operator+(const Term& other) const {
        if (exponent != other.exponent)
            throw std::invalid_argument("Cannot add terms with different exponents");
        return Term(coefficient + other.coefficient, exponent);
    }

    bool operator==(const Term& other) const {
        return (coefficient == other.coefficient) && (exponent == other.exponent);
    }

    friend std::istream& operator>>(std::istream& is, Term& term) {
        term.parseTerm(is);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Term& term) {
        if (term.coefficient == 0) {
            os << "0";
            return os;
        }

        // Вывод коэффициента
        if (term.coefficient != 1 || term.exponent == 0) {
            if (term.coefficient == -1 && term.exponent != 0)
                os << "-";
            else
                os << term.coefficient;
        }

        // Вывод переменной и степени
        if (term.exponent > 0) {
            os << "x";
            if (term.exponent > 1)
                os << "^" << term.exponent;
        }

        return os;
    }

    friend class Polynomial;
};

#endif // TERM_H
