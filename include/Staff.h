#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>

class Staff {
protected:
    std::string name;
    int age;

public:
    Staff(const std::string& n, int a) : name(n), age(a) {
        std::cout << "Staff()" << std::endl;
    }

    virtual ~Staff() {
        std::cout << "~Staff()" << std::endl;
    }

    virtual void show() const = 0; // Чисто виртуальная функция
};

#endif
