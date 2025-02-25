#ifndef PLANETLOGIC_HPP
#define PLANETLOGIC_HPP

#include "planet/planet.hpp"


// Функция для выбора действия пользователем
int ChoiceMethod();

// Загрузка данных из файла
void loadDataFromFile(Planet*& planets, int& count, const char* filename);

// Сохранение данных в файл
void saveDataToFile(Planet* planets, int count, const char* filename);

// Добавление новой планеты
void addNewPlanet(Planet*& planets, int& count);

// Удаление планеты
void removePlanet(Planet*& planets, int& count);

// Редактирование данных о планете
void editPlanet(Planet* planets, int count);

// Сортировка планет по диаметру
void sortPlanetsByDiameter(Planet* planets, int count);

// Вывод всех планет на экран
void printAllPlanets(Planet* planets, int count);


#endif // PLANETLOGIC_HPP
