// tasks.cpp
#include "tasks.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <random>
#include <string>
#include <vector>
#include <map>
#include "Box.h"
#include "Inventory.h"

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

    std::cout << str << std::endl;
}
void task2() {
    std::cout << "Выполняется Задание №2\n";
    std::string str;
    std::cout << "введите текст \n";
    std::getline(std::cin, str);

    int a = str.find(" ");
    int b = str.find(".");
    // std::cout << a << "\n" << b << std::endl;

    if ((b - a > 0) && (a * b > 0)) {
        std::string newStr = str.substr(a, b - a);
        std::cout << newStr << std::endl;
    }
}
void task3() {
    std::cout << "Выполняется Задание №3\n";
    std::ifstream allStr("allStr.txt");
    std::ofstream numStr("numStr.txt");
    std::string line;

    if (allStr.is_open() && numStr.is_open()) {
        while (std::getline(allStr, line)) {
            if (isdigit(line.front())) {
                numStr << line << std::endl;
            }
        }
    }
    allStr.close();
    numStr.close();
}

void PrintVec(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << "\n";
    }
    std::cout << std::endl;
}

void task4() {
    std::cout << "Выполняется Задание №4\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-100, 100);

    std::vector<int> vec;
    for (int i = 0; i < 6; i++) {
        vec.push_back(distrib(gen));
    }
    PrintVec(vec);

    std::vector<int> vec2;
    for (int i : vec) {
        if (i < 0) {
            vec2.push_back(i);
        }
    }
    PrintVec(vec2);

    vec.erase(vec.begin() + 4);
    PrintVec(vec);
}

void PrintVec(const std::vector<Inventory>& v) {
    for (Inventory i : v) {
        std::cout << i << "\n";
    }
    std::cout << std::endl;
}

void task5() {
    std::cout << "Выполняется Задание №5\n";

    std::vector<Inventory> warehouse{
        {"Отверка", 99,  0  },
        {"Молоток", 430, 10 },
        {"Гайки",     70,  100},
        {"Профиль", 540, 0  },
        {"Уголок",   230, 9  },
        {"Доска",     350, 17 }
    };

    PrintVec(warehouse);

    std::vector<Inventory> absent;
    for (Inventory i : warehouse) {
        if (i.getOnHand() == 0) {
            absent.push_back(i);
        }
    }

    PrintVec(absent);
}

void PrintList(std::list<int>& l) {
    for (int i : l) {
        std::cout << i << "\n";
    }
    std::cout << std::endl;
}

void task6() {
    std::cout << "Выполняется Задание №6\n";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-100, 100);

    std::list<int> lis;
    for (int i = 0; i < 6; i++) {
        lis.push_back(distrib(gen));
    }
    PrintList(lis);

    std::list<int> negLis = lis;
    negLis.remove_if([](int n) { return n >= 0; });

    PrintList(negLis);

    lis.erase(std::next(lis.begin(), 4));
    PrintList(lis);
}

void PrintList(std::list<Box>& b) {
    for (Box i : b) {
        std::cout << i << "\n";
    }
    std::cout << std::endl;
}

void task7() {
    std::cout << "Выполняется Задание №7\n";
    std::list<Box> boxes = {Box(1, 2, 63), Box(14, 57, 19), Box(7, 32, 20), Box(5, 13, 23), Box(10, 19, 45), Box(19, 9, 59)};

    PrintList(boxes);

    boxes.sort();
    std::cout << "Самая большая коробка: " << *std::prev(boxes.end()) << std::endl;
}
void task8() {
    std::cout << "Выполняется Задание №8\n";

    std::map<char, int> charMap;

    charMap['A'] = int('A');
    charMap['B'] = int('B');
    charMap['C'] = int('C');
    charMap['D'] = int('D');
    charMap['E'] = int('E');

    for (const auto& [key, value] : charMap) {
        std::cout << key << " : " << value << std::endl;
    }

    auto it = charMap.begin();
    std::advance(it, 1);
    if (it != charMap.end()) {
        charMap.erase(it);
    }

    std::cout << "после удаления" << std::endl;
    for (const auto& [key, value] : charMap) {
        std::cout << key << " : " << value << std::endl;
    }
}
void task9() {
    std::cout << "Выполняется Задание №9\n";
}
