#include <iostream>
#include <string.h>
#include "head_lab1.hpp"

int interactive() {
    std::cout << "Интерактивный режим запущен." << std::endl;
    // Здесь можно добавить логику для интерактивного режима
    return 0;
}

int demo() {
    std::cout << "Демо-режим запущен." << std::endl;
    // Здесь можно добавить логику для демо-режима
    return 0;
}

int main(int argc, char *argv[]) {
    bool isInteractive = false;    // По умолчанию демо-режим.

    // Если "i" передается в качестве аргумента, то программа переходит в интерактивный режим
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        return interactive();
    } else {
        return demo();
    }
}
