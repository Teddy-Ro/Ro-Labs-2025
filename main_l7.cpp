#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include "Administration.h"
#include "Engineer.h"
#include "Worker.h"
#include "lib/stack.h"

void print(const MyStack<Staff*>& container) {
    if (container.empty()) {
        std::cout << "Контейнер пуст!" << std::endl;
        return;
    }

    MyStack<Staff*> temp(container);
    std::size_t i = 0;

    while (!temp.empty()) {
        std::cout << "index " << i++ << ": ";
        temp.topInf()->show();
        temp.pop();
    }
}

void remove(MyStack<Staff*>& container, std::size_t index) {
    if (container.empty()) {
        std::cerr << "Контейнер пуст!" << std::endl;
        return;
    }

    MyStack<Staff*> temp;
    std::size_t currentSize = 0;

    MyStack<Staff*> counter(container);
    while (!counter.empty()) {
        currentSize++;
        counter.pop();
    }

    if (index >= currentSize) {
        std::cerr << "Invalid index!" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < index; ++i) {
        temp.push(container.topInf());
        container.pop();
    }

    Staff* toDelete = container.topInf();
    container.pop();
    delete toDelete;

    while (!temp.empty()) {
        container.push(temp.topInf());
        temp.pop();
    }
}

void clear(MyStack<Staff*>& container) {
    while (!container.empty()) {
        Staff* toDelete = container.topInf();
        container.pop();
        delete toDelete;
    }
}

int main() {
    MyStack<Staff*> container;
    int choice = -1;
    char bufferName[100];
    char bufferJob[100];

    while (choice != 0) {
        std::cout << "\nМеню:\n"
                  << "1. Добавить рабочего\n"
                  << "2. Добавить инженера\n"
                  << "3. Добавить администратора\n"
                  << "4. Вывести всех\n"
                  << "5. Удалить по индексу\n"
                  << "6. Очистить контейнер\n"
                  << "0. Выход\n"
                  << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Введите имя: ";
                std::cin.getline(bufferName, 100);

                std::cout << "Введите возраст: ";
                int age;
                std::cin >> age;
                std::cin.ignore();

                std::cout << "Введите должность: ";
                std::cin.getline(bufferJob, 100);

                container.push(new Worker(bufferName, age, bufferJob));
                break;
            }
            case 2: {
                std::cout << "Введите имя: ";
                std::cin.getline(bufferName, 100);

                std::cout << "Введите возраст: ";
                int age;
                std::cin >> age;
                std::cin.ignore();

                std::cout << "Введите отдел: ";
                std::cin.getline(bufferJob, 100);

                container.push(new Engineer(bufferName, age, bufferJob));
                break;
            }
            case 3: {
                std::cout << "Введите имя: ";
                std::cin.getline(bufferName, 100);

                std::cout << "Введите возраст: ";
                int age;
                std::cin >> age;
                std::cin.ignore();

                std::cout << "Введите роль: ";
                std::cin.getline(bufferJob, 100);

                container.push(new Administration(bufferName, age, bufferJob));
                break;
            }
            case 4:
                print(container);
                break;
            case 5: {
                std::size_t index;
                std::cout << "Введите индекс: ";
                std::cin >> index;
                remove(container, index);
                break;
            }
            case 6:
                clear(container);
                break;
            case 0:
                clear(container);
                break;
            default:
                std::cout << "Неверный выбор!" << std::endl;
        }
    }

    return 0;
}
