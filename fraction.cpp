#include "fraction.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stdexcept>

int N_DEC = 4;

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

void Fraction::simplify(int& numerator, int& denominator) {
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        std::cerr << "denominator cannot be 0\n";
        throw std::invalid_argument("denominator cannot be 0");
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    simplify();
}

Fraction::Fraction(const char* str) : numerator(0), denominator(1) {
    double integer = 0;
    int num = 0;
    int den = 1;

    std::stringstream ss(str);
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

    if (std::fmod(integer, 1.0) != 0.0) {
        Fraction doub(integer);
        numerator = doub.numerator;
        denominator = doub.denominator;
        return;

    }

    if (den == 0) {
        throw std::invalid_argument("denominator cannot be 0");
        den = 1;
    }

    simplify(num, den);

    if (integer < 0){
        numerator = integer * den - std::abs(num);
    } else {
        numerator = integer * den + num;
    }
    denominator = den;
    simplify();
}

Fraction::Fraction(double value) : numerator(0), denominator(1) {
    double precision = pow(10, N_DEC);
    numerator = static_cast<int>(round(value * precision));
    denominator = static_cast<int>(precision);
    simplify();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
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
    fraction.simplify();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    int numerator = fraction.numerator;
    int denominator = fraction.denominator;

    if (numerator == 0) {
        out << 0;
    } else if (denominator == 1) {
        out << numerator;
    } else if (std::abs(numerator) < denominator) {
        out << numerator << "/" << denominator;
    } else {
        int integerPart = numerator / denominator;
        int num = numerator % denominator;
        out << integerPart << " " << std::abs(num) << "/" << denominator;
    }
    return out;
}
