#pragma once
#include <string>
#include <iostream>



class Inventory {
 private:
    std::string item;
    double cost;
    int onHand;
 public:
    Inventory();
    Inventory(const std::string& i, double c = 0, int onH = 0);
    ~Inventory();

    const std::string& getItem() const { return item; }
    double getCost() const { return cost; }
    int getOnHand() const { return onHand; }

    void setItem(const std::string& i) { item = i; }
    void setCost(double c) { cost = c; }
    void setOnHand(int onH) { onHand = onH; }

    friend bool operator==(const Inventory& lhs, const Inventory& rhs);
    friend std::ostream& operator<<(std::ostream&out, const Inventory& inv);
};

Inventory::Inventory() : item(), cost(0), onHand(0){}
Inventory::Inventory(const std::string& i, double c, int onH) : item(i), cost(c), onHand(onH) {}

Inventory::~Inventory() {}

bool operator==(const Inventory& lhs, const Inventory& rhs) {
    return lhs.item == rhs.item && lhs.cost == rhs.cost;
}

std::ostream& operator<<(std::ostream&out, const Inventory& inv) {
    out<< inv.item << ' ' << inv.cost  << ' ' << inv.onHand;
    return out;
}
