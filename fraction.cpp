#include "fraction.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

const int N_DEC = 4;  // Default precision for double conversion

int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

void Fraction::simplify() {
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() : numerator(0), denominator(1), integerPart(0), isNegative(false) {
    std::cout << "Fraction()\n";
}

Fraction::Fraction(int numerator, int denominator) : integerPart(0), isNegative(false) {
    std::cout << "Fraction(int, int)\n";
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero.\n";
        this->numerator = 0;
        this->denominator = 1;
        return;
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    simplify();
}

Fraction::Fraction(const char* str) : numerator(0), denominator(1), integerPart(0), isNegative(false) {
    int sign = 1;
    int integer = 0;
    int num = 0;
    int den = 1;

    std::stringstream ss(str);
    if (str[0] == '-') {
        sign = -1;
        ss.ignore();
    } else if (str[0] == '+') {
        ss.ignore();
    }

    if (strchr(str, '/')) {
        if (strchr(str, ' ')) {
            ss >> integer;
            ss >> num;
            ss.ignore();
            ss >> den;
        } else {
            ss >> num;
            ss.ignore();
            ss >> den;
        }
    } else {
        ss >> integer;
    }

    integer *= sign;
    num *= sign;

    this->integerPart = integer;
    this->numerator = num + std::abs(integer) * den;
    this->denominator = den;
    this->isNegative = integer < 0 || num < 0;
    simplify();
}

Fraction::Fraction(double value) : numerator(0), denominator(1), integerPart(0), isNegative(false) {
    std::cout << "Fraction(double)\n";
    isNegative = value < 0;
    value = std::abs(value);
    integerPart = static_cast<int>(value);
    value -= integerPart;

    double precision = pow(10, N_DEC);
    numerator = static_cast<int>(round(value * precision));
    denominator = static_cast<int>(precision);

    if (isNegative) {
        numerator = -numerator;
    }
    simplify();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

int Fraction::getIntegerPart() const {
    return integerPart;
}

bool Fraction::getIsNegative() const {
    return isNegative;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator+=(double value) {
    Fraction other(value);
    *this += other;
    return *this;
}

Fraction& Fraction::operator+=(int value) {
    numerator += value * denominator;
    simplify();
    return *this;
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result = *this;
    result += other;
    return result;
}

Fraction Fraction::operator+(double value) const {
    Fraction other(value);
    return *this + other;
}

Fraction Fraction::operator+(int value) const {
    Fraction result = *this;
    result += value;
    return result;
}

Fraction operator+(double value, const Fraction& fraction) {
    Fraction other(value);
    return other + fraction;
}

Fraction operator+(int value, const Fraction& fraction) {
    Fraction result(value, 1);
    return result + fraction;
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char buffer[256];
    in.getline(buffer, sizeof(buffer));
    Fraction temp(buffer);
    fraction.numerator = temp.numerator;
    fraction.denominator = temp.denominator;
    fraction.integerPart = temp.integerPart;
    fraction.isNegative = temp.isNegative;
    fraction.simplify();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    int integerPart = fraction.numerator / fraction.denominator;
    int numerator = fraction.numerator % fraction.denominator;

    if (fraction.numerator == 0) {
        out << 0;
    } else if (numerator == 0) {
        out << integerPart;
    } else {
        if (integerPart != 0) {
            out << integerPart << " " << abs(numerator) << "/" << fraction.denominator;
        } else {
            out << numerator << "/" << fraction.denominator;
        }
    }
    return out;
}
