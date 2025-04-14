// main.cpp
#include <iostream>
#include "vecLib/MySet.h"

int main() {
    // Тестирование с int
    MySet<int> set1;
    set1.AddElement(1);
    set1.AddElement(4);
    set1.AddElement(5);
    set1.AddElement(6);
    
    MySet<int> set2;
    set2.AddElement(1);
    set2.AddElement(2);
    set2.AddElement(3);
    set2.AddElement(4);
    
    std::cout << "Set1: " << set1 << std::endl;
    std::cout << "Set2: " << set2 << std::endl;
    
    MySet<int> union_set = set1 + set2;
    MySet<int> intersection_set = set1 * set2;
    MySet<int> difference_set = set1 - set2;
    
    std::cout << "Union: " << union_set << std::endl;
    std::cout << "Intersection: " << intersection_set << std::endl;
    std::cout << "Difference: " << difference_set << std::endl;
    
    std::cout << "Set1 == Set2: " << (set1 == set2) << std::endl;
    
    // Тестирование с char*
    MySet<char*> str_set1;
    str_set1.AddElement("apple");
    str_set1.AddElement("banana");
    str_set1.AddElement("orange");
    
    MySet<char*> str_set2;
    str_set2.AddElement("banana");
    str_set2.AddElement("kiwi");
    str_set2.AddElement("apple");
    
    std::cout << "\nString Set1: " << str_set1 << std::endl;
    std::cout << "String Set2: " << str_set2 << std::endl;
    
    MySet<char*> str_union = str_set1 + str_set2;
    MySet<char*> str_intersection = str_set1 * str_set2;
    MySet<char*> str_difference = str_set1 - str_set2;
    
    std::cout << "String Union: " << str_union << std::endl;
    std::cout << "String Intersection: " << str_intersection << std::endl;
    std::cout << "String Difference: " << str_difference << std::endl;
    
    std::cout << "String Set1 == String Set2: " << (str_set1 == str_set2) << std::endl;
    
    return 0;
}