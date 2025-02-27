#include <cstring>    // для работы с char*
#include <fstream>
#include <iostream>
#include "house.hpp"

// Конструкторы
House::House() : address(nullptr), floors(0), apartments(0), hasElevator(false) {}

House::House(const char* addr, int f, int a, bool elevator)
    : floors(f), apartments(a), hasElevator(elevator) {
    address = new char[strlen(addr) + 1];
    std::strncpy(address, addr, strlen(addr) + 1);  // Копируем адрес с ограничением длины
    address[strlen(addr)] = '\0';  // Убедимся, что строка завершается нулевым символом
}

// Деструктор
House::~House() {
    delete[] address;  // Освобождаем память
}

// Конструктор копирования
House::House(const House& other)
    : floors(other.floors), apartments(other.apartments), hasElevator(other.hasElevator) {
    address = new char[strlen(other.address) + 1];
    std::strncpy(address, other.address, strlen(other.address) + 1);  // Копируем адрес с ограничением длины
    address[strlen(other.address)] = '\0';  // Убедимся, что строка завершается нулевым символом
}

// Оператор присваивания
House& House::operator=(const House& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        delete[] address;     // Освобождаем старую память
        address = new char[strlen(other.address) + 1];
        std::strncpy(address, other.address, strlen(other.address) + 1);  // Копируем адрес с ограничением длины
        address[strlen(other.address)] = '\0';  // Убедимся, что строка завершается нулевым символом
        floors = other.floors;
        apartments = other.apartments;
        hasElevator = other.hasElevator;
    }
    return *this;
}

// Геттеры и сеттеры
const char* House::getAddress() const { return address; }
int House::getFloors() const { return floors; }
int House::getApartments() const { return apartments; }
bool House::getHasElevator() const { return hasElevator; }

void House::setAddress(const char* addr) {
    delete[] address;  // Освобождаем старую память
    address = new char[strlen(addr) + 1];
    std::strncpy(address, addr, strlen(addr) + 1);  // Копируем адрес с ограничением длины
    address[strlen(addr)] = '\0';  // Убедимся, что строка завершается нулевым символом
}
void House::setFloors(int f) { floors = f; }
void House::setApartments(int a) { apartments = a; }
void House::setHasElevator(bool elevator) { hasElevator = elevator; }

// Перегрузка операторов ввода/вывода
std::ostream& operator<<(std::ostream& os, const House& house) {
    os << house.address << " " << house.floors << " " << house.apartments
       << " " << (house.hasElevator ? 1 : 0);
    return os;
}

std::istream& operator>>(std::istream& is, House& house) {
    char buffer[256];
    is >> buffer >> house.floors >> house.apartments >> house.hasElevator;
    house.setAddress(buffer);  // Устанавливаем адрес через сеттер
    return is;
}

// Перегрузка операторов сравнения
bool House::operator<(const House& other) const {
    return floors < other.floors;  // Сортировка по количеству этажей
}

bool House::operator>(const House& other) const {
    return other < *this;  // Используем существующую перегрузку <
}

bool House::operator==(const House& other) const {
    return std::strcmp(address, other.address) == 0 && floors == other.floors && apartments == other.apartments && hasElevator == other.hasElevator;
}

// Чтение БД из файла
House* House::readFromFile(const char* filename, int& count) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        count = 0;
        return nullptr;
    }

    // Читаем количество домов
    file >> count;
    if (count <= 0) {
        std::cerr << "Некорректное количество домов в файле." << std::endl;
        file.close();
        return nullptr;
    }

    // Создаем массив домов
    House* database = new House[count];

    // Читаем данные о каждом доме
    for (int i = 0; i < count; ++i) {
        char addr[100];
        int floors;
        int apartments;
        bool hasElevator;

        file >> addr >> floors >> apartments >> hasElevator;

        // Создаем объект House и добавляем его в массив
        database[i] = House(addr, floors, apartments, hasElevator);
    }

    file.close();
    return database;
}

// Запись БД в файл
void House::writeToFile(const char* filename, House* database, int count) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << count << '\n' << std::flush;

        for (int i = 0; i < count; ++i) {
            file << database[i] << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл для записи: " << filename << std::endl;
    }
}

// Сортировка БД
void House::sortHouses(House* database, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (database[j] > database[j + 1]) {
                House temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
}

// Добавление нового объекта в БД
void House::addHouse(House*& database, int& count, const House& house) {
    House* newDatabase = new House[count + 1];
    for (int i = 0; i < count; ++i) {
        newDatabase[i] = database[i];
    }
    newDatabase[count] = house;
    count++;
    delete[] database;
    database = newDatabase; // Обновляем указатель database
}

// Удаление объекта из БД
void House::removeHouse(House*& database, int& count, const char* houseAddress) {
    int indexToRemove = -1;
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(database[i].getAddress(), houseAddress) == 0) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove == -1) {
        std::cerr << "Дом с адресом " << houseAddress << " не найден." << std::endl;
        return;
    }

    House* newDatabase = new House[count - 1];
    int newIndex = 0;
    for (int i = 0; i < count; ++i) {
        if (i != indexToRemove) {
            newDatabase[newIndex++] = database[i];
        }
    }

    std::cout << "Дом: " << houseAddress << " удален." << std::endl;

    count--;
    delete[] database; // Освобождаем память старого массива
    database = newDatabase; // Обновляем указатель на новый массив
}

// Редактирование БД
bool House::editHouse(House* database, int count, const char* houseAddress, const House& newHouseData) {
    for (int i = 0; i < count; ++i) {
        if (std::strcmp(database[i].getAddress(), houseAddress) == 0) {
            database[i] = newHouseData;  // Заменяем данные дома
            return true;                  // Успешно отредактировано
        }
    }
    std::cerr << "Дом с адресом " << houseAddress << " не найден." << std::endl;
    return false; // Дом не найден
}

// Вывод БД на экран
void House::printHouses(House* database, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << database[i] << std::endl;
    }
}
