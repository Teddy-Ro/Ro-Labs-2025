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

    std::cin.ignore();

    std::cout << "Enter planet name: ";
    std::cin.getline(newName, 100);

    std::cout << "Enter planet diameter: ";
    std::cin >> newDiameter;

    std::cout << "Enter number of satellites: ";
    std::cin >> newSatellites;

    std::cout << "Does the planet have life? (1 for yes, 0 for no): ";
    int lifeInput;
    std::cin >> lifeInput;
    newHasLife = lifeInput == 1;

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
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

template<typename T>
void switchPlanet(T* planets, int& count, const char* filename) {
    while (true) {
        switch (ChoicePlanetMethod()) {
            case 1:
                loadDataFromFile(planets, count, filename);
                break;

            case 2:
                saveDataToFile(planets, count, filename);
                break;

            case 3:
                addNewPlanet(planets, count);
                break;

            case 4:
                removePlanet(planets, count);
                break;

            case 5:
                editPlanet(planets, count);
                break;

            case 6:
                sortPlanetsByDiameter(planets, count);
                break;

            case 7:
                printAllPlanets(planets, count);
                break;

            case 8:
                delete[] planets;
                std::cout << "Выход из программы.\n";
                return;

            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }
}

void loadDataFromFile(Planet*& planets, int& count, const char* filename) {
    planets = Planet::readFromFile(filename, count);
    std::cout << "Данные загружены из файла.\n";
}

void saveDataToFile(Planet* planets, int count, const char* filename) {
    Planet::writeToFile(filename, planets, count);
    std::cout << "Данные сохранены в файл.\n";
}

void addNewPlanet(Planet*& planets, int& count) {
    Planet newPlanet = FillPlanetsParametrs();
    Planet::addPlanet(planets, count, newPlanet);
    std::cout << "Планета добавлена.\n";
}

void removePlanet(Planet*& planets, int& count) {
    char name[100];
    std::cout << "Введите название планеты для удаления: ";
    std::cin >> name;
    Planet::removePlanet(planets, count, name);
}

void editPlanet(Planet* planets, int count) {
    char name[100];
    std::cout << "Введите название планеты для редактирования: ";
    std::cin >> name;

    Planet newPlanetData = FillPlanetsParametrs();

    Planet::editPlanet(planets, count, name, newPlanetData);
}

void sortPlanetsByDiameter(Planet* planets, int count) {
    Planet::sortPlanets(planets, count);
    std::cout << "Планеты отсортированы по диаметру.\n";
}

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
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

template<typename T>
void switchHouse(T* houses, int& count, const char* filename) {
    while (true) {
        switch (ChoiceHouseMethod()) {
            case 1:
                loadDataFromFileHouse(houses, count, filename);
                break;

            case 2:
                saveDataToFileHouse(houses, count, filename);
                break;

            case 3:
                addNewHouse(houses, count);
                break;

            case 4:
                removeHouse(houses, count);
                break;

            case 5:
                editHouse(houses, count);
                break;

            case 6:
                sortHousesByFloors(houses, count);
                break;

            case 7:
                printAllHouses(houses, count);
                break;

            case 8:
                delete[] houses;
                std::cout << "Выход из программы.\n";
                return;

            default:
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }
}

void loadDataFromFileHouse(House*& houses, int& count, const char* filename) {
    houses = House::readFromFile(filename, count);
    std::cout << "Данные загружены из файла.\n";
}

void saveDataToFileHouse(House* houses, int count, const char* filename) {
    House::writeToFile(filename, houses, count);
    std::cout << "Данные сохранены в файл.\n";
}

void addNewHouse(House*& houses, int& count) {
    House newHouse = FillHouseParametrs();
    House::addHouse(houses, count, newHouse);
    std::cout << "Дом добавлен.\n";
}

void removeHouse(House*& houses, int& count) {
    char addr[100];
    std::cout << "Введите адрес дома для удаления: ";
    std::cin >> addr;
    House::removeHouse(houses, count, addr);
}

void editHouse(House* houses, int count) {
    char addr[100];
    std::cout << "Введите адрес дома для редактирования: ";
    std::cin >> addr;

    House newHouseData = FillHouseParametrs();

    House::editHouse(houses, count, addr, newHouseData);
}

void sortHousesByFloors(House* houses, int count) {
    House::sortHouses(houses, count);
    std::cout << "Дома отсортированы по количеству этажей.\n";
}

void printAllHouses(House* houses, int count) {
    House::printHouses(houses, count);
}

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

template void planetSpace::switchPlanet<Planet>(Planet* planets, int& count, const char* filename);
template void houseSpace::switchHouse<House>(House* houses, int& count, const char* filename);
