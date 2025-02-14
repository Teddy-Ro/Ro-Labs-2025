#include <iostream>
#include "mymath/mymath.hpp"
#include "myprint/myprint.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;

    myprint::PrintString(myprint::InputString());

    return 0;
}
