#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
 private:
    int numerator;
    int denominator;

    void simplify();
    void simplify(int&, int&);
    int gcd(int a, int b);

 public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(const char* str);
    Fraction(double value);

    int getNumerator() const;
    int getDenominator() const;
    bool getIsNegative() const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator+=(double value);
    Fraction& operator+=(int value);

    Fraction operator+(const Fraction& other) const;
    Fraction operator+(double value) const;
    Fraction operator+(int value) const;

    friend Fraction operator+(double value, const Fraction& fraction);
    friend Fraction operator+(int value, const Fraction& fraction);

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

#endif
