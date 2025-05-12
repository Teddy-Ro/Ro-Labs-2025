#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Staff.h"
#include <iostream>
#include <cstring>

class Administration : public Staff {
protected:
    char role[100];

public:
    Administration(const char* n, int a, const char* r)
        : Staff(n, a) {
        strncpy(role, r, 99);
        role[99] = '\0';
        std::cout << "Administration()" << std::endl;
    }

    ~Administration() override {
        std::cout << "~Administration()" << std::endl;
    }

    void show() const override {
        std::cout << "администратор: " << name << ", возраст: " << age
                  << ", роль: " << role << std::endl;
    }
};

#endif
