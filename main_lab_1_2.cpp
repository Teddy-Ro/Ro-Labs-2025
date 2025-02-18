#include <iostream>
#include "include/myprint.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    myprint::PrintString(myprint::InputString());

    return 0;
}
