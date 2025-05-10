#include "vecLib/MyVector.h"
#include "Worker.h"
#include "Engineer.h"
#include "Administration.h"
#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

void print(const MyVector<Staff*>& container) {
    if (container.GetSize() == 0) {
        cout << "Container is empty!" << endl;
        return;
    }
    for (size_t i = 0; i < container.GetSize(); ++i) {
        cout << "Index " << i << ": ";
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
        cout << "\nMenu:\n"
             << "1. Add Worker\n"
             << "2. Add Engineer\n"
             << "3. Add Administration\n"
             << "4. Print all\n"
             << "5. Remove by index\n"
             << "6. Clear container\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                cout << "Enter name: "; cin.getline(name, 100);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter position: "; cin.getline(position, 100);
                container.AddElement(new Worker(name, age, position));
                break;
            }
            case 2: {
                cout << "Enter name: "; cin.getline(name, 100);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter department: "; cin.getline(department, 100);
                container.AddElement(new Engineer(name, age, department));
                break;
            }
            case 3: {
                cout << "Enter name: "; cin.getline(name, 100);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter role: "; cin.getline(role, 100);
                container.AddElement(new Administration(name, age, role));
                break;
            }
            case 4:
                print(container);
                break;
            case 5: {
                size_t index;
                cout << "Enter index: "; cin >> index;
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
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
