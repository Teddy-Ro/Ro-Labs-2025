#ifndef PLANETLOGIC_HPP
#define PLANETLOGIC_HPP

#include <iostream>
#include <string>
#include "house/house.hpp"
#include "planet/planet.hpp"

int choiceLib();

namespace planetSpace {

Planet FillPlanetsParametrs();

int ChoicePlanetMethod();

template<typename T>
void switchPlanet(T* planets, int& count, const char* filename);

void loadDataFromFile(Planet*& planets, int& count, const char* filename);

void saveDataToFile(Planet* planets, int count, const char* filename);

void addNewPlanet(Planet*& planets, int& count);

void removePlanet(Planet*& planets, int& count);

void editPlanet(Planet* planets, int count);

void sortPlanetsByDiameter(Planet* planets, int count);

void printAllPlanets(Planet* planets, int count);

}  // namespace planetSpace

namespace houseSpace {

int ChoiceHouseMethod();

template<typename T>
void switchHouse(T* houses, int& count, const char* filename);

void loadDataFromFileHouse(House*& houses, int& count, const char* filename);

void saveDataToFileHouse(House* houses, int count, const char* filename);

void addNewHouse(House*& houses, int& count);

void removeHouse(House*& houses, int& count);

void editHouse(House* houses, int count);

void sortHousesByFloors(House* houses, int count);

void printAllHouses(House* houses, int count);

House FillHouseParametrs();

}  // namespace houseSpace

#endif
