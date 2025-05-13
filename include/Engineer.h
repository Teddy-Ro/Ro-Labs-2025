#ifndef ENGINEER_H
#define ENGINEER_H

#include "Staff.h"
#include <cstring>
#include <iostream>

class Engineer : public Staff {
protected:
    char* department;
public:
    Engineer(const char* n, int a, const char* dep)
        : Staff(n, a) {
        department = new char[strlen(dep) + 1];
        strcpy(department, dep);
        std::cout << "Engineer()" << std::endl;
    }

    ~Engineer() override {
        delete[] department;
        std::cout << "~Engineer()" << std::endl;
    }

    void show() const override {
        std::cout << "Инженер: " << name << ", возраст: " << age
            << ", отдел: " << department << std::endl;
    }
};

#endif
