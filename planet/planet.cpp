#include <algorithm>  // для сортировки
#include <cstring>    // для работы с char*
#include <fstream>
#include <iostream>
#include "planet.hpp"

// Конструкторы
Planet::Planet() : name(nullptr), diameter(0), satellites(0), hasLife(false) {}

Planet::Planet(const char* n, long long d, int s, bool l) : diameter(d), satellites(s), hasLife(l) {
    name = new char[strlen(n) + 1];  // Выделяем память для имени
    std::strcpy(name, n);            // Копируем имя
}

// Деструктор
Planet::~Planet() {
    delete[] name;  // Освобождаем память
}

// Конструктор копирования
Planet::Planet(const Planet& other) : diameter(other.diameter), satellites(other.satellites), hasLife(other.hasLife) {
    name = new char[strlen(other.name) + 1];
    std::strcpy(name, other.name);
}

// Оператор присваивания
Planet& Planet::operator=(const Planet& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        delete[] name;     // Освобождаем старую память
        name = new char[strlen(other.name) + 1];
        std::strcpy(name, other.name);
        diameter = other.diameter;
        satellites = other.satellites;
        hasLife = other.hasLife;
    }
    return *this;
}

// Геттеры и сеттеры
const char* Planet::getName() const { return name; }
long long Planet::getDiameter() const { return diameter; }
int Planet::getSatellites() const { return satellites; }
bool Planet::getHasLife() const { return hasLife; }

void Planet::setName(const char* n) {
    delete[] name;  // Освобождаем старую память
    name = new char[strlen(n) + 1];
    std::strcpy(name, n);
}
void Planet::setDiameter(long long d) { diameter = d; }
void Planet::setSatellites(int s) { satellites = s; }
void Planet::setHasLife(bool l) { hasLife = l; }

// Перегрузка операторов ввода/вывода
std::ostream& operator<<(std::ostream& os, const Planet& planet) {
    os << "Name: " << planet.name << ", Diameter: " << planet.diameter << " km, Satellites: " << planet.satellites
       << ", Life: " << (planet.hasLife ? "Yes" : "No");
    return os;
}

std::istream& operator>>(std::istream& is, Planet& planet) {
    char buffer[256];
    is >> buffer >> planet.diameter >> planet.satellites >> planet.hasLife;
    planet.setName(buffer);  // Устанавливаем имя через сеттер
    return is;
}

// Перегрузка операторов сравнения
bool Planet::operator<(const Planet& other) const {
    return diameter < other.diameter;  // Сортировка по диаметру
}

bool Planet::operator==(const Planet& other) const {
    return std::strcmp(name, other.name) == 0 && diameter == other.diameter && satellites == other.satellites && hasLife == other.hasLife;
}

// Чтение БД из файла
Planet* Planet::readFromFile(const char* filename, int& count) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        count = 0;
        return nullptr;
    }

    // Определяем количество планет в файле (простой подход)
    count = 0;
    char buffer[256];
    while (file.getline(buffer, sizeof(buffer))) {
        count++;
    }
    file.clear();
    file.seekg(0, std::ios::beg); // Возвращаемся в начало файла

    Planet* database = new Planet[count];
    for (int i = 0; i < count; ++i) {
        file >> database[i];
        if (file.fail()) {
            // Обработка ошибки чтения
            delete[] database;
            count = 0;
            file.close();
            return nullptr;
        }
    }
    file.close();
    return database;
}

// Запись БД в файл
void Planet::writeToFile(const char* filename, Planet* database, int count) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < count; ++i) {
            file << database[i] << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
    }
}

// Сортировка БД
void Planet::sortPlanets(Planet* database, int count) {
    std::sort(database, database + count, [](const Planet& a, const Planet& b) {
        return a < b; // Используем перегруженный оператор <
    });
}

// Добавление нового объекта в БД
Planet* Planet::addPlanet(Planet* database, int& count, const Planet& planet) {
    Planet* newDatabase = new Planet[count + 1];
    for (int i = 0; i < count; ++i) {
        newDatabase[i] = database[i];
    }
    newDatabase[count] = planet;
    count++;
    delete[] database;
    return newDatabase;
}

// Удаление объекта из БД
Planet* Planet::removePlanet(Planet* database, int& count, const char* planetName) {
    int indexToRemove = -1;
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(database[i].getName(), planetName) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        std::cerr << "Планета с именем " << planetName << " не найдена." << std::endl;
        return database; // Ничего не меняем, возвращаем старую БД
    }

    Planet* newDatabase = new Planet[count - 1];
    int newIndex = 0;
    for (int i = 0; i < count; ++i) {
        if (i != indexToRemove) {
            newDatabase[newIndex++] = database[i];
        }
    }
    count--;
    delete[] database;
    return newDatabase;
}

// Редактирование БД
bool Planet::editPlanet(Planet* database, int count, const char* planetName, const Planet& newPlanetData) {
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(database[i].getName(), planetName) == 0) {
            database[i] = newPlanetData;  // Заменяем данные планеты
            return true;                  // Успешно отредактировано
        }
    }
    std::cerr << "Планета с именем " << planetName << " не найдена." << std::endl;
    return false; // Планета не найдена
}

// Вывод БД на экран
void Planet::printPlanets(Planet* database, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << database[i] << std::endl;
    }
}
