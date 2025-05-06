#include <iostream>
#include <limits>
#include "Polynomial.h"
#include "Term.h"

int main() {
    try {
    Polynomial p1, p2;

    std::cout << "первый полином: ";
    std::cin >> p1;
    std::cout << p1 << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "второй полином: ";
    std::cin >> p2;
    std::cout << p2 << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial product = p1 * p2;

    std::cout << "+: " << sum << std::endl;
    std::cout << "-: " << diff << std::endl;
    std::cout << "*: " << product << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
