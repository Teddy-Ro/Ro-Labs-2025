#ifndef ENGINEER_H
#define ENGINEER_H

#include "Staff.h"
#include <iostream>

class Engineer : public Staff {
protected:
    std::string department;

public:
    Engineer(const std::string& n, int a, const std::string& dep)
        : Staff(n, a), department(dep) {
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
