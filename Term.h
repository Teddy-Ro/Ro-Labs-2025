#ifndef TERM_H
#define TERM_H

#include <cctype>
#include <iostream>
#include <stdexcept>

class Term {
 private:
    int coefficient;
    int exponent;

    void parseTerm(std::istream& is) {
        coefficient = 0;
        exponent = 0;
        int sign = 1;
        int expSign = 1;

        while (is.peek() == ' ') is.get();

        if (is.peek() == '-') {
            sign = -1;
            is.get();
        } else if (is.peek() == '+') {
            is.get();
        }

        while (is.peek() == ' ') is.get();

        if (isdigit(is.peek())) {
            is >> coefficient;
            coefficient *= sign;
        } else {
            coefficient = sign * 1;
        }

        while (is.peek() == ' ') is.get();

        if (is.peek() == 'x') {
            is.get();
            exponent = 1;

            while (is.peek() == ' ') is.get();

            if (is.peek() == '^') {
                is.get();
                while (is.peek() == ' ') is.get();

                if (is.peek() == '-') {
                    expSign = -1;
                    is.get();
                } else if (is.peek() == '+') {
                    is.get();
                }

                if (isdigit(is.peek())) {
                    is >> exponent;
                    exponent *= expSign;
                } else {
                    throw std::invalid_argument("Invalid exponent");
                }
            }
        } else {
            exponent = 0;
        }
        while (is.peek() == ' ') is.get();
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

    bool operator==(const Term& other) const { return (coefficient == other.coefficient) && (exponent == other.exponent); }

    friend std::istream& operator>>(std::istream& is, Term& term) {
        term.parseTerm(is);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Term& term) {
        if (term.coefficient == 0) {
            os << "0";
            return os;
        }

        if (term.coefficient != 1 || term.exponent == 0) {
            if (term.coefficient == -1 && term.exponent != 0)
                os << "-";
            else
                os << term.coefficient;
        }

        if (term.exponent != 0) {
            os << "x";
            if (term.exponent > 1 || term.exponent < 0)
                os << "^" << term.exponent;
        }

        return os;
    }

    friend class Polynomial;
};

#endif  // TERM_H
