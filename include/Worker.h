#ifndef WORKER_H
#define WORKER_H

#include "Staff.h"
#include <iostream>
#include <cstring>

class Worker : public Staff {
protected:
    char position[100];

public:
    Worker(const char* n, int a, const char* pos)
        : Staff(n, a) {
        strncpy(position, pos, 99);
        position[99] = '\0';
        std::cout << "Worker()" << std::endl;
    }

    ~Worker() override {
        std::cout << "~Worker()" << std::endl;
    }

    void show() const override {
        std::cout << "Рабочий: " << name << ", возраст: " << age
                  << ", позиция: " << position << std::endl;
    }
};

#endif
