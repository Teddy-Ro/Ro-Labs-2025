#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Staff.h"
#include <iostream>

class Administration : public Staff {
protected:
    std::string role;

public:
    Administration(const std::string& n, int a, const std::string& r)
        : Staff(n, a), role(r) {
        std::cout << "Administration()" << std::endl;
    }

    ~Administration() override {
        std::cout << "~Administration()" << std::endl;
    }

    void show() const override {
        std::cout << "Administration: " << name << ", Age: " << age
                  << ", Role: " << role << std::endl;
    }
};

#endif
