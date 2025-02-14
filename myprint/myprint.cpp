#include "myprint.hpp"
#include <iostream>
#include <string>

namespace myprint {
std::string InputString() {
    std::string input;
    std::cout << "Введите строку: ";

    std::getline(std::cin, input);
    return input;
}

void PrintString(std::string string) {
    std::cout << string << std::endl;
}

int IputNumber() {
    int num;
    std::cout << "Введите число: ";
    std::cin >> num;
    return num;
}
}  // namespace myprint
