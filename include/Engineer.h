#ifndef ENGINEER_H
#define ENGINEER_H

#include "Staff.h"
#include <iostream>
#include <cstring>

class Engineer : public Staff {
protected:
    char department[100];

public:
    Engineer(const char* n, int a, const char* dep)
        : Staff(n, a) {
        strncpy(department, dep, 99);
        department[99] = '\0';
        std::cout << "Engineer()" << std::endl;
    }

    ~Engineer() override {
        std::cout << "~Engineer()" << std::endl;
    }

    void show() const override {
        std::cout << "Engineer: " << name << ", Age: " << age
                  << ", Department: " << department << std::endl;
    }
};

#endif
