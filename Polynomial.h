// Polynomial.h
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include "vecLib/MyVector.h"

class Polynomial {
private:
    MyVector<Term> terms; // Хранение термов

    void simplify() {
        // Сортировка термов по убыванию степени
        for (size_t i = 0; i < terms.GetSize(); ++i) {
            for (size_t j = i + 1; j < terms.GetSize(); ++j) {
                if (terms[i].exponent < terms[j].exponent) {
                    Term temp = terms[i];
                    terms[i] = terms[j];
                    terms[j] = temp;
                }
            }
        }
    }

public:
    Polynomial() = default;

    Polynomial(int constant) {
        terms.AddElement(Term(constant, 0));
    }

    Polynomial(const Term& term) {
        terms.AddElement(term);
    }

    Polynomial(const Polynomial& other) = default;
    Polynomial& operator=(const Polynomial& other) = default;

    Polynomial& operator+=(const Term& term) {
        for (size_t i = 0; i < terms.GetSize(); ++i) {
            if (terms[i].exponent == term.exponent) {
                terms[i] = terms[i] + term;
                simplify();
                return *this;
            }
        }
        terms.AddElement(term);
        simplify();
        return *this;
    }

    friend std::istream& operator>>(std::istream& is, Polynomial& poly) {
        Term term;
        while (is >> term) {
            poly += term;
            if (is.peek() == '\n') break;
        }
        poly.simplify();
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        if (poly.terms.GetSize() == 0) {
            os << "0";
            return os;
        }

        for (size_t i = 0; i < poly.terms.GetSize(); ++i) {
            const Term& term = poly.terms[i];
            if (i > 0) {
                os << (term.getCoefficient() > 0 ? " + " : " - ");
            }
            os << Term(std::abs(term.getCoefficient()), term.getExponent());
        }
        return os;
    }
};

#endif // POLYNOMIAL_H
