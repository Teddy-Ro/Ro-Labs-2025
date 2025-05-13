#ifndef WORKER_H
#define WORKER_H

#include "Staff.h"
#include <cstring>

class Worker : public Staff {
protected:
    char* position;
public:
    Worker(const char* n, int a, const char* pos)
        : Staff(n, a) {
        position = new char[strlen(pos) + 1];
        strcpy(position, pos);
        std::cout << "Administration()" << std::endl;
    }

    ~Worker() override {
        delete[] position;
        std::cout << "~Administration()" << std::endl;
    }

    void show() const override {
        std::cout << "Рабочий: " << name << ", возраст: " << age
            << ", должность: " << position << std::endl;
    }
};

#endif
