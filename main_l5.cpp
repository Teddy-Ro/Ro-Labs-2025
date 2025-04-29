// main_l5.cpp
#include <iostream>
#include "vecLib/MySet.h"
#include "vecLib/MyVector.h"

int main() {
    // Тестирование MyVector
    MyVector<const char*> v("Hello!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    std::cout << "Вектор v: " << v << std::endl;

    v.AddElement("Привет!");
    v.AddElement("Привет!");
    v.AddElement("Привет!");
    std::cout << "Вектор v: " << v << std::endl;

    MyVector<const char*> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;

    for (size_t i = 0; i < v1.GetMaxSize(); i++)
        v1.DeleteElementForIndex(0);  // Удаление по индексу
    std::cout << "Вектор v1: " << v1 << std::endl;

    // Тестирование MySet
    MySet<const char*> s("Yes");
    s.AddElement("Привет!");
    s.AddElement("No");
    const char* str = "Hello!";
    s.AddElement(str);
    std::cout << "Множество s: " << s << std::endl;

    MySet<const char*> s1;
    s1.AddElement("Cat");
    s1.AddElement("No");
    s1.AddElement("Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;

    MySet<const char*> s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s1 + s;
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    MySet<const char*> s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;

    std::cout << "Сравнение множеств:\n";
    std::cout << "s3 == s2: " << (s3 == s2 ? "Да" : "Нет") << std::endl;
    std::cout << "s3 == s1: " << (s3 == s1 ? "Да" : "Нет") << std::endl;
    std::cout << "s1 == s3: " << (s1 == s3 ? "Да" : "Нет") << std::endl;

    return 0;
}
