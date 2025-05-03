#include <iostream>

class Box {
    double a;
    double b;
    double c;

public:
    Box() : a(0), b(0), c(0) {}
    Box(double a, double b, double c) : a(a), b(b), c(c) {}

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    double volume() const {
        return a * b * c;
    }

    bool operator<(const Box& other) const {
        return this->volume() < other.volume();
    }

    bool operator==(const Box& other) const {
        return a == other.a && b == other.b && c == other.c;
    }

    friend std::ostream& operator<<(std::ostream& out, const Box& box);
};

std::ostream& operator<<(std::ostream& out, const Box& box) {
    out << box.a << ", " << box.b << ", " << box.c;
    return out;
}


// int main() {
//     // Создаём список из 6 коробок с заданными размерами
//     std::list<Box> boxes = {
//         Box(1, 2, 63),
//         Box(14, 57, 19),
//         Box(7, 32, 20),
//         Box(5, 13, 23),
//         Box(10, 19, 45),
//         Box(19, 9, 59)
//     };

//     std::cout << "Список коробок:\n";
//     printList(boxes);

//     // Находим коробку с максимальным объёмом
//     auto maxBoxIt = std::max_element(boxes.begin(), boxes.end(),
//         [](const Box& b1, const Box& b2) {
//             return b1.volume() < b2.volume();
//         });

//     if (maxBoxIt != boxes.end()) {
//         std::cout << "\nКоробка с наибольшим объёмом:\n";
//         std::cout << "Box(" << maxBoxIt->getA() << ", " << maxBoxIt->getB() << ", " << maxBoxIt->getC() << ")\n";
//         std::cout << "Объём: " << maxBoxIt->volume() << "\n";
//     }

//     return 0;
// }
