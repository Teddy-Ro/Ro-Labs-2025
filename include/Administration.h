#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Staff.h"
#include <cstring>

class Administration : public Staff {
protected:
    char* role;
public:
    Administration(const char* n, int a, const char* r)
        : Staff(n, a) {
        role = new char[strlen(r) + 1];
        strcpy(role, r);
        std::cout << "Administration()" << std::endl;
    }

    ~Administration() override {
        delete[] role;
        std::cout << "~Administration()" << std::endl;
    }

    void show() const override {
        std::cout << "Администрация: " << name << ", возраст: " << age
            << ", роль: " << role << std::endl;
    }
};

#endif
