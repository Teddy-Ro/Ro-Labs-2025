#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <iostream>

class House {
 private:
    char* address;       // Адрес дома (динамическая память)
    int floors;          // Количество этажей
    int apartments;      // Количество квартир
    bool hasElevator;    // Наличие лифта

 public:
    // Конструкторы
    House();
    House(const char* addr, int f, int a, bool elevator);

    // Деструктор
    ~House();

    // Конструктор копирования
    House(const House& other);

    // Оператор присваивания
    House& operator=(const House& other);

    // Геттеры и сеттеры
    const char* getAddress() const;
    int getFloors() const;
    int getApartments() const;
    bool getHasElevator() const;

    void setAddress(const char* addr);
    void setFloors(int f);
    void setApartments(int a);
    void setHasElevator(bool elevator);

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const House& house);
    friend std::istream& operator>>(std::istream& is, House& house);

    // Перегрузка операторов сравнения
    bool operator<(const House& other) const;
    bool operator>(const House& other) const;
    bool operator==(const House& other) const;

    // Статические методы для работы с базой данных
    static House* readFromFile(const char* filename, int& count);
    static void writeToFile(const char* filename, House* database, int count);
    static void sortHouses(House* database, int count);
    static void addHouse(House*& database, int& count, const House& house);
    static void removeHouse(House*& database, int& count, const char* houseAddress);
    static bool editHouse(House* database, int count, const char* houseAddress, const House& newHouseData);
    static void printHouses(House* database, int count);
};

#endif
