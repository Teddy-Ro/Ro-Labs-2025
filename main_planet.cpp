#include <iostream>
#include "planetLogic.hpp"
#include <fstream>
#include "house/house.hpp"
#include "planet/planet.hpp"

int main() {
    int choice = choiceLib();
    int count = 0;
    Planet* planetDataBase = nullptr;
    House* houseDataBase = nullptr;
    const char* filename;

    switch (choice) {
        case 1: {
            filename = "planets.txt";
            planetSpace::switchPlanet(planetDataBase, count, filename);
            break;
        }
        case 2: {
            filename = "house.txt";
            houseSpace::switchHouse(houseDataBase, count, filename);
            break;
        }
        default:
            std::cout << "Некорректный выбор.\n";
            return 1;
    }

    // Remember to free memory if the program reaches this point
    if (choice == 1 && planetDataBase != nullptr) {
        delete[] planetDataBase;
    } else if (choice == 2 && houseDataBase != nullptr) {
        delete[] houseDataBase;
    }

    return 0;
}
