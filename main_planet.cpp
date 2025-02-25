#include <iostream>
#include "planetLogic.hpp"
#include "planet/planet.hpp" // Подключаем заголовочный файл класса Planet



int main() {
    Planet* planets = nullptr; // Указатель на массив планет
    int count = 0; // Количество планет в базе данных
    char filename[] = "planets.txt"; // Имя файла с базой данных



    while (true) {
        // Вывод меню

        switch (ChoiceMethod()) {
            case 1: // Загрузка данных из файла
                loadDataFromFile(planets, count, filename);
                break;

            case 2: // Сохранение данных в файл
                saveDataToFile(planets, count, filename);
                break;

            case 3: // Добавление новой планеты
                addNewPlanet(planets, count);
                break;

            case 4: // Удаление планеты
                removePlanet(planets, count);
                break;

            case 5: // Редактирование данных о планете
                editPlanet(planets, count);
                break;

            case 6: // Сортировка планет по диаметру
                sortPlanetsByDiameter(planets, count);
                break;

            case 7: // Вывод всех планет на экран
                printAllPlanets(planets, count);
                break;

            case 8: // Выход из программы
                delete[] planets; // Освобождение памяти
                std::cout << "Выход из программы.\n";
                return 0;

            default: // Некорректный выбор
                std::cout << "Некорректный выбор. Попробуйте снова.\n";
                break;
        }
    }

    return 0;
}
