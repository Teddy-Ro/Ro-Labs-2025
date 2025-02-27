#include "planetLogic.hpp"
#include <fstream>
#include <iostream>
#include "house/house.hpp"
#include "planet/planet.hpp"

int choiceLib() {
    int choice;
    std::cout << "Выберите библиотеку:\n";
    std::cout << "1. Planet\n";
    std::cout << "2. House\n";
    std::cout << "Введите номер выбранной библиотеки: ";
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Некорректный выбор. Попробуйте снова.\n";
        std::cout << "Введите номер выбранной библиотеки: ";
        std::cin >> choice;
    }

    return choice;
}

namespace planetSpace {

Planet FillPlanetsParametrs() {
    char newName[100];
    long long newDiameter;
    int newSatellites;
    bool newHasLife;

    std::cin.ignore();  // Очистка буфера от предыдущих символов новой строки

    std::cout << "Enter planet name: ";
    std::cin.getline(newName, 100);  // Считываем имя планеты

    std::cout << "Enter planet diameter: ";
    std::cin >> newDiameter;

    std::cout << "Enter number of satellites: ";
    std::cin >> newSatellites;

    std::cout << "Does the planet have life? (1 for yes, 0 for no): ";
    int lifeInput;
    std::cin >> lifeInput;
    newHasLife = lifeInput == 1;

    // Очистка потока ввода после чтения целых чисел
    std::cin.ignore();

    Planet newPlanetData(newName, newDiameter, newSatellites, newHasLife);
    return newPlanetData;
}

int ChoicePlanetMethod() {
    int choice;
    while (true) {
        std::cout << "\n=== Меню ===\n";
        std::cout << "1. Загрузить данные из файла\n";
        std::cout << "2. Сохранить данные в файл\n";
        std::cout << "3. Добавить новую планету\n";
        std::cout << "4. Удалить планету\n";
        std::cout << "5. Редактировать данные о планете\n";
        std::cout << "6. Сортировать планеты по диаметру\n";
        std::cout << "7. Вывести все планеты на экран\n";
        std::cout << "8. Выход\n";
        std::cout << "Выберите опцию: ";

        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 8) {
                return choice;
            } else {
                std::cout << "Недопустимый выбор. Пожалуйста, выберите опцию от 1 до 8.\n";
            }
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
            std::cin.clear();              // Очищаем флаг ошибки
            std::cin.ignore(10000, '\n');  // Игнорируем оставшиеся символы в буфере
        }
    }
}

template<typename T>
void switchPlanet(T* planets, int& count, const char* filename) {
    while (true) {
        // Вывод меню

        switch (ChoicePlanetMethod()) {
            case 1:  // Загрузка данных из файла
                loadDataFromFile(planets, count, filename);
                break;

            case 2:  // Сохранение данных в файл
                saveDataToFile(planets, count, filename);
                break;

            case 3:  // Добавление новой планеты
                addNewPlanet(planets, count);
                break;

            case 4:  // Удаление планеты
                removePlanet(planets, count);
                break;

            case 5:  // Редактирование данных о планете
                editPlanet(planets, count);
                break;

            case 6:  // Сортировка планет по диаметру
                sortPlanetsByDiameter(planets, count);
                break;

            case 7:  // Вывод всех планет на экран
                printAllPlanets(planets, count);
                break;

            case 8:                // Выход из программы
                delete[] planets;  // Освобождение памяти
                std::cout << "Выход из программы.\n";
                return;

            default:  // Некорректный выбор
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }
}

// Загрузка данных из файла
void loadDataFromFile(Planet*& planets, int& count, const char* filename) {
    planets = Planet::readFromFile(filename, count);
    std::cout << "Данные загружены из файла.\n";
}

// Сохранение данных в файл
void saveDataToFile(Planet* planets, int count, const char* filename) {
    Planet::writeToFile(filename, planets, count);
    std::cout << "Данные сохранены в файл.\n";
}

// Добавление новой планеты
void addNewPlanet(Planet*& planets, int& count) {
    Planet newPlanet = FillPlanetsParametrs();
    Planet::addPlanet(planets, count, newPlanet);
    std::cout << "Планета добавлена.\n";
}

// Удаление планеты
void removePlanet(Planet*& planets, int& count) {
    char name[100];
    std::cout << "Введите название планеты для удаления: ";
    std::cin >> name;
    Planet::removePlanet(planets, count, name);
}

// Редактирование данных о планете
void editPlanet(Planet* planets, int count) {
    char name[100];
    std::cout << "Введите название планеты для редактирования: ";
    std::cin >> name;

    Planet newPlanetData = FillPlanetsParametrs();

    Planet::editPlanet(planets, count, name, newPlanetData);
}

// Сортировка планет по диаметру
void sortPlanetsByDiameter(Planet* planets, int count) {
    Planet::sortPlanets(planets, count);
    std::cout << "Планеты отсортированы по диаметру.\n";
}

// Вывод всех планет на экран
void printAllPlanets(Planet* planets, int count) {
    Planet::printPlanets(planets, count);
}
}  // namespace planetSpace

namespace houseSpace {
int ChoiceHouseMethod() {
    int choice;
    while (true) {
        std::cout << "\n=== Меню ===\n";
        std::cout << "1. Загрузить данные из файла\n";
        std::cout << "2. Сохранить данные в файл\n";
        std::cout << "3. Добавить новый дом\n";
        std::cout << "4. Удалить дом\n";
        std::cout << "5. Редактировать данные о доме\n";
        std::cout << "6. Сортировать дома по количеству этажей\n";
        std::cout << "7. Вывести все дома на экран\n";
        std::cout << "8. Выход\n";
        std::cout << "Выберите опцию: ";

        if (std::cin >> choice) {
            if (choice >= 1 && choice <= 8) {
                return choice;
            } else {
                std::cout << "Недопустимый выбор. Пожалуйста, выберите опцию от 1 до 8.\n";
            }
        } else {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число.\n";
            std::cin.clear();              // Очищаем флаг ошибки
            std::cin.ignore(10000, '\n');  // Игнорируем оставшиеся символы в буфере
        }
    }
}

template<typename T>
void switchHouse(T* houses, int& count, const char* filename) {
    while (true) {
        // Вывод меню

        switch (ChoiceHouseMethod()) {
            case 1:  // Загрузка данных из файла
                loadDataFromFileHouse(houses, count, filename);
                break;

            case 2:  // Сохранение данных в файл
                saveDataToFileHouse(houses, count, filename);
                break;

            case 3:  // Добавление нового дома
                addNewHouse(houses, count);
                break;

            case 4:  // Удаление дома
                removeHouse(houses, count);
                break;

            case 5:  // Редактирование данных о доме
                editHouse(houses, count);
                break;

            case 6:  // Сортировка домов по количеству этажей
                sortHousesByFloors(houses, count);
                break;

            case 7:  // Вывод всех домов на экран
                printAllHouses(houses, count);
                break;

            case 8:                // Выход из программы
                delete[] houses;  // Освобождение памяти
                std::cout << "Выход из программы.\n";
                return;

            default:  // Некорректный выбор
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }
}

// Загрузка данных из файла
void loadDataFromFileHouse(House*& houses, int& count, const char* filename) {
    houses = House::readFromFile(filename, count);
    std::cout << "Данные загружены из файла.\n";
}

// Сохранение данных в файл
void saveDataToFileHouse(House* houses, int count, const char* filename) {
    House::writeToFile(filename, houses, count);
    std::cout << "Данные сохранены в файл.\n";
}

// Добавление нового дома
void addNewHouse(House*& houses, int& count) {
    House newHouse = FillHouseParametrs();
    House::addHouse(houses, count, newHouse);
    std::cout << "Дом добавлен.\n";
}

// Удаление дома
void removeHouse(House*& houses, int& count) {
    char addr[100];
    std::cout << "Введите адрес дома для удаления: ";
    std::cin >> addr;
    House::removeHouse(houses, count, addr);
}

// Редактирование данных о доме
void editHouse(House* houses, int count) {
    char addr[100];
    std::cout << "Введите адрес дома для редактирования: ";
    std::cin >> addr;

    House newHouseData = FillHouseParametrs();

    House::editHouse(houses, count, addr, newHouseData);
}

// Сортировка домов по количеству этажей
void sortHousesByFloors(House* houses, int count) {
    House::sortHouses(houses, count);
    std::cout << "Дома отсортированы по количеству этажей.\n";
}

// Вывод всех домов на экран
void printAllHouses(House* houses, int count) {
    House::printHouses(houses, count);
}

// Функция для заполнения параметров дома
House FillHouseParametrs() {
    char addr[100];
    std::cout << "Введите адрес дома: ";
    std::cin >> addr;
    int floors;
    std::cout << "Введите количество этажей: ";
    std::cin >> floors;
    int apartments;
    std::cout << "Введите количество квартир: ";
    std::cin >> apartments;
    bool hasElevator;
    std::cout << "Наличие лифта (1 - да, 0 - нет): ";
    std::cin >> hasElevator;

    return House(addr, floors, apartments, hasElevator);
}

}  // namespace houseSpace

// Template Specializations
template void planetSpace::switchPlanet<Planet>(Planet* planets, int& count, const char* filename);
template void houseSpace::switchHouse<House>(House* houses, int& count, const char* filename);
