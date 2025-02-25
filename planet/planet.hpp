#ifndef PLANET_HPP
#define PLANET_HPP

#include <iostream>

class Planet {
 private:
    char* name;          // Название планеты (динамическая память)
    long long diameter;  // Диаметр планеты
    int satellites;      // Количество спутников
    bool hasLife;        // Наличие жизни

 public:
    // Конструкторы
    Planet();
    Planet(const char* n, long long d, int s, bool l);

    // Деструктор
    ~Planet();

    // Конструктор копирования
    Planet(const Planet& other);

    // Оператор присваивания
    Planet& operator=(const Planet& other);

    // Геттеры и сеттеры
    const char* getName() const;
    long long getDiameter() const;
    int getSatellites() const;
    bool getHasLife() const;

    void setName(const char* n);
    void setDiameter(long long d);
    void setSatellites(int s);
    void setHasLife(bool l);

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::istream& operator>>(std::istream& is, Planet& planet);

    // Перегрузка операторов сравнения
    bool operator<(const Planet& other) const;
    bool operator==(const Planet& other) const;

    // Статические методы для работы с базой данных
    static Planet* readFromFile(const char* filename, int& count);
    static void writeToFile(const char* filename, Planet* database, int count);
    static void sortPlanets(Planet* database, int count);
    static Planet* addPlanet(Planet* database, int& count, const Planet& planet);
    static Planet* removePlanet(Planet* database, int& count, const char* planetName);
    static bool editPlanet(Planet* database, int count, const char* planetName, const Planet& newPlanetData);
    static void printPlanets(Planet* database, int count);
};

#endif
