// tasks.cpp
#include "tasks.h"
#include <iostream>
#include <string>

void task1() {
    std::cout << "Выполняется Задание №1\n";
    std::string str1, str2, str3;
    std::cout << "введите слово 1 \n";
    std::cin >> str1;

    std::cout << "введите слово 2 \n";
    std::cin >> str2;

    std::cout << "введите слово 3 \n";
    std::cin >> str3;

    std::string str = std::string(1, str1.front());
    str += str2.front();
    str += str3.front();

    std::cout<< str<<std::endl;
}
void task2() {
    std::cout << "Выполняется Задание №2\n";
}
void task3() {
    std::cout << "Выполняется Задание №3\n";
}
void task4() {
    std::cout << "Выполняется Задание №4\n";
}
void task5() {
    std::cout << "Выполняется Задание №5\n";
}
void task6() {
    std::cout << "Выполняется Задание №6\n";
}
void task7() {
    std::cout << "Выполняется Задание №7\n";
}
void task8() {
    std::cout << "Выполняется Задание №8\n";
}
void task9() {
    std::cout << "Выполняется Задание №9\n";
}
