#ifndef PLANET_HPP
#define PLANET_HPP

#include <iostream>

class Planet {
 private:
    char* name;
    long long diameter;
    int satellites;
    bool hasLife;

 public:
    Planet();
    Planet(const char* n, long long d, int s, bool l);

    ~Planet();

    Planet(const Planet& other);

    Planet& operator=(const Planet& other);

    const char* getName() const;
    long long getDiameter() const;
    int getSatellites() const;
    bool getHasLife() const;

    void setName(const char* n);
    void setDiameter(long long d);
    void setSatellites(int s);
    void setHasLife(bool l);

    friend std::ostream& operator<<(std::ostream& os, const Planet& planet);
    friend std::istream& operator>>(std::istream& is, Planet& planet);

    bool operator<(const Planet& other) const;
    bool operator>(const Planet& other) const;
    bool operator==(const Planet& other) const;

    static Planet* readFromFile(const char* filename, int& count);
    static void writeToFile(const char* filename, Planet* database, int count);
    static void sortPlanets(Planet* database, int count);
    static void addPlanet(Planet*& database, int& count, const Planet& planet);
    static void removePlanet(Planet*& database, int& count, const char* planetName);
    static bool editPlanet(Planet* database, int count, const char* planetName, const Planet& newPlanetData);
    static void printPlanets(Planet* database, int count);
};

#endif
