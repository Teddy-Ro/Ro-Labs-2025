#include "vecLib/MyVector.h"
#include "Worker.h"
#include "Engineer.h"
#include "Administration.h"
#include <iostream>
#include <limits>

using namespace std;

// Функции print, remove, clear
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
    int choice;

    do {
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
                string name, position;
                int age;
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter position: "; getline(cin, position);
                container.AddElement(new Worker(name, age, position));
                break;
            }
            case 2: {
                string name, department;
                int age;
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter department: "; getline(cin, department);
                container.AddElement(new Engineer(name, age, department));
                break;
            }
            case 3: {
                string name, role;
                int age;
                cout << "Enter name: "; getline(cin, name);
                cout << "Enter age: "; cin >> age;
                cin.ignore();
                cout << "Enter role: "; getline(cin, role);
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
    } while (choice != 0);

    return 0;
}
