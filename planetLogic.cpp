#include "planetLogic.hpp"
#include <iostream>
#include <fstream>
#include "planet/planet.hpp"

Planet FillPlanetsParametrs() {
    char newName[100];
    long long newDiameter;
    int newSatellites;
    bool newHasLife;

    std::cin.ignore(); // Очистка буфера от предыдущих символов новой строки

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


int ChoiceMethod() {
    int choice;
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
    std::cin >> choice;
    return choice;
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
