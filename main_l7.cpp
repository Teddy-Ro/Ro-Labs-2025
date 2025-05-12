#include <cstring>
#include <iostream>
#include <limits>
#include "Administration.h"
#include "Engineer.h"
#include "Worker.h"
#include "vecLib/MyVector.h"

using namespace std;

void print(const MyVector<Staff*>& container) {
    if (container.GetSize() == 0) {
        cout << "Контейнер пуст!" << endl;
        return;
    }
    for (size_t i = 0; i < container.GetSize(); ++i) {
        cout << "index " << i << ": ";
        container[i]->show();
    }
}

void remove(MyVector<Staff*>& container, size_t index) {
    if (index >= container.GetSize()) {
        cerr << "Invalid index!" << endl;
        return;
    }
    delete container[index];
    container.DeleteElement(container[index]);
}

void clear(MyVector<Staff*>& container) {
    for (size_t i = 0; i < container.GetSize(); ++i) {
        delete container[i];
    }
    container = MyVector<Staff*>();
}

int main() {
    MyVector<Staff*> container;
    int choice = -1;
    char name[100];
    char position[100];
    char department[100];
    char role[100];
    int age;

    while (choice != 0) {
        cout << "\nМеню:\n"
             << "1. Добавить рабочего\n"
             << "2. Добавить инженера\n"
             << "3. Добавить администратора\n"
             << "4. Вывести всех\n"
             << "5. Удалить по индексу\n"
             << "6. Очистить контейнер\n"
             << "0. Выход\n"
             << "Выберите действие: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                cout << "Введите имя: ";
                cin.getline(name, 100);
                cout << "Введите возраст: ";
                cin >> age;
                cin.ignore();
                cout << "Введите должность: ";
                cin.getline(position, 100);
                container.AddElement(new Worker(name, age, position));
                break;
            }
            case 2: {
                cout << "Введите имя: ";
                cin.getline(name, 100);
                cout << "Введите возраст: ";
                cin >> age;
                cin.ignore();
                cout << "Введите отдел: ";
                cin.getline(department, 100);
                container.AddElement(new Engineer(name, age, department));
                break;
            }
            case 3: {
                cout << "Введите имя: ";
                cin.getline(name, 100);
                cout << "Введите возраст: ";
                cin >> age;
                cin.ignore();
                cout << "Введите роль: ";
                cin.getline(role, 100);
                container.AddElement(new Administration(name, age, role));
                break;
            }
            case 4:
                print(container);
                break;
            case 5: {
                size_t index;
                cout << "Введите индекс: ";
                cin >> index;
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
                cout << "Неверный выбор!" << endl;
        }
    }


    return 0;
}
