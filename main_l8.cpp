// main.cpp
#include <iostream>
#include "tasks.h"
#include <limits>

int main() {
    int choice;
    std::cout << "Выберите номер задания (1-9): ";
    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        case 6: task6(); break;
        case 7: task7(); break;
        case 8: task8(); break;
        case 9: task9(); break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, выберите от 1 до 9.\n";
    }
    return 0;
}
