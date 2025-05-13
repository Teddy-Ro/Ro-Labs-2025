#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <cstring>

class Staff {
protected:
    char *name;
    int age;

public:
    Staff(const char* n, int a) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        std::cout << "Staff()" << std::endl;
    }


    virtual ~Staff() {
    delete[] name;
    std::cout << "~Staff()" << std::endl;
}


    virtual void show() const = 0;
};

#endif
