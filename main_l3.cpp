#include <iomanip>
#include <iostream>
#include "fraction.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите дробь: \n";
    Fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;


    int a = 10;
    int b = 14;
    Fraction fr1(a, b);
    std::cout << "fr1=" << fr1 << std::endl;

    Fraction fr2;
    std::cout << "fr2=" << fr2 << std::endl;

    Fraction fr3 = "-1 4/8";

    std::cout << "fr3=" << fr3 << std::endl;

    Fraction x(z);
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f=" << f << std::endl;


    Fraction y = x + z;
    std::cout << "y=" << y << std::endl;

    y += x;
    std::cout << "y=" << y << std::endl;
    f += dbl / 2;

    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;

    return 0;
}
