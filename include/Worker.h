#ifndef WORKER_H
#define WORKER_H

#include "Staff.h"
#include <iostream>

class Worker : public Staff {
protected:
    std::string position;

public:
    Worker(const std::string& n, int a, const std::string& pos)
        : Staff(n, a), position(pos) {
        std::cout << "Worker()" << std::endl;
    }

    ~Worker() override {
        std::cout << "~Worker()" << std::endl;
    }

    void show() const override {
        std::cout << "Worker: " << name << ", Age: " << age
                  << ", Position: " << position << std::endl;
    }
};

#endif
