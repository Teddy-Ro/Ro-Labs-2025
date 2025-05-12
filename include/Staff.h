#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <cstring>

class Staff {
protected:
    char name[100];
    int age;

public:
    Staff(const char* n, int a) : age(a) {
        strncpy(name, n, 99);
        name[99] = '\0';
        std::cout << "Staff()" << std::endl;
    }

    virtual ~Staff() {
        std::cout << "~Staff()" << std::endl;
    }

    virtual void show() const = 0;
};

#endif
