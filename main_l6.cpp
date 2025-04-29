#include <iostream>
#include "Term.h"
#include "Polynomial.h"

int main() {
    // Пример работы с Term
    Term t1(3, 2), t2(-1, 2);
    Term t3 = t1 + t2;
    std::cout << t3 << std::endl; // 2x^2

    // Пример работы с Polynomial
    Polynomial p1;
    std::cout << "Enter polynomial: ";
    std::cin >> p1;
    std::cout << "Polynomial: " << p1 << std::endl;

    return 0;
}
