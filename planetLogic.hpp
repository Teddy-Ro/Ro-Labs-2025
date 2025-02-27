#ifndef PLANETLOGIC_HPP
#define PLANETLOGIC_HPP

#include <iostream>
#include <string>
#include "house/house.hpp"
#include "planet/planet.hpp"

// Function to choose the library
int choiceLib();

namespace planetSpace {

// Function to fill planet parameters
Planet FillPlanetsParametrs();

// Function for choosing a method in the Planet menu
int ChoicePlanetMethod();

// Template function to switch between planet methods
template<typename T>
void switchPlanet(T* planets, int& count, const char* filename);

// Load data from file
void loadDataFromFile(Planet*& planets, int& count, const char* filename);

// Save data to file
void saveDataToFile(Planet* planets, int count, const char* filename);

// Add a new planet
void addNewPlanet(Planet*& planets, int& count);

// Remove a planet
void removePlanet(Planet*& planets, int& count);

// Edit planet data
void editPlanet(Planet* planets, int count);

// Sort planets by diameter
void sortPlanetsByDiameter(Planet* planets, int count);

// Print all planets
void printAllPlanets(Planet* planets, int count);

}  // namespace planetSpace

namespace houseSpace {

// Function for choosing a method in the House menu
int ChoiceHouseMethod();

// Template function to switch between house methods
template<typename T>
void switchHouse(T* houses, int& count, const char* filename);

// Load data from file
void loadDataFromFileHouse(House*& houses, int& count, const char* filename);

// Save data to file
void saveDataToFileHouse(House* houses, int count, const char* filename);

// Add a new house
void addNewHouse(House*& houses, int& count);

// Remove a house
void removeHouse(House*& houses, int& count);

// Edit house data
void editHouse(House* houses, int count);

// Sort houses by floors
void sortHousesByFloors(House* houses, int count);

// Print all houses
void printAllHouses(House* houses, int count);

// Function to fill house parameters
House FillHouseParametrs();

}  // namespace houseSpace

#endif
