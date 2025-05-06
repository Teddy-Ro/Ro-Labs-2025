#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"
#include "vecLib/MyVector.h"

class Polynomial {
private:
    MyVector<Term> terms;

    void simplify() {
        for (size_t i = 0; i < terms.GetSize(); ++i) {
            for (size_t j = i + 1; j < terms.GetSize(); ++j) {
                if (terms[i].exponent < terms[j].exponent) {
                    std::swap(terms[i], terms[j]);
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

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result(*this);
        for (size_t i = 0; i < other.terms.GetSize(); ++i) {
            result += other.terms[i];
        }
        result.simplify();
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result(*this);
        for (size_t i = 0; i < other.terms.GetSize(); ++i) {
            Term neg_term = other.terms[i];
            neg_term.coefficient *= -1;
            result += neg_term;
        }
        result.simplify();
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < terms.GetSize(); ++i) {
            for (size_t j = 0; j < other.terms.GetSize(); ++j) {
                Term product(
                    terms[i].getCoefficient() * other.terms[j].getCoefficient(),
                    terms[i].getExponent() + other.terms[j].getExponent()
                );
                result += product;
            }
        }
        result.simplify();
        return result;
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
