// main.cpp
#include <iostream>
#include "vecLib/MyVector.h"
#include "vecLib/MySet.h"

char* create_string(const char* src) {
    size_t len = strlen(src);
    char* dst = new char[len + 1];
    strncpy(dst, src, len);
    dst[len] = '\0';
    return dst;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Работа с MyVector<char*>
    MyVector<char*> v;
    v.AddElement(create_string("Hello!"));
    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    std::cout << "Вектор v: " << v << std::endl;

    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    v.AddElement(create_string("Привет!"));
    std::cout << "Вектор v: " << v << std::endl;

    MyVector<char*> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;

    while (v1.GetSize() > 0) {
        v1.DeleteElementByIndex(0);
    }
    std::cout << "Вектор v1: " << v1 << std::endl;

    // Работа с MySet<char*>
    MySet<char*> s;
    s.AddElement(create_string("Yes"));
    MySet<char*> s1;
    MySet<char*> s2;

    s.AddElement(create_string("Привет!"));
    s.AddElement(create_string("No"));
    char* str = create_string("Hello!");
    s.AddElement(str);
    std::cout << "Множество s: " << s << std::endl;

    s1.AddElement(create_string("Cat"));
    s1.AddElement(create_string("No"));
    s1.AddElement(create_string("Привет!"));
    std::cout << "Множество s1: " << s1 << std::endl;

    s2 = s1 - s;
    std::cout << "Множество s2 = s1 - s: " << s2 << std::endl;

    s2 = s - s1;
    std::cout << "Множество s2 = s - s1: " << s2 << std::endl;

    s2 = s1 + s;
    std::cout << "Множество s2 = s1 + s: " << s2 << std::endl;

    s2 = s1 * s;
    std::cout << "Множество s2 = s1 * s: " << s2 << std::endl;

    MySet<char*> s3 = s2;
    std::cout << "Множество s3 = s2: " << s3 << std::endl;

    if (s3 == s2) {
        std::cout << "Множество s3 == s2\n";
    } else {
        std::cout << "Множество s3 != s2\n";
    }

    return 0;
}
