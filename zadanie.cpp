#include <iostream>
#include <string>
#include <cmath>
using namespace std;

double krug(double radius) {
    const double pi = 3.14159265359;
    return pi * pow(radius, 2);
}

double treug(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Использование: " << argv[0] << " <операция> <операнды>." << endl;
        return 1;
    }

    string operation = argv[2];

    if (operation == "circle") {
        if (argc != 4) {
            cout << "Неверное количество операндов для операции 'circle'. Используйте один операнд (радиус)." << endl;
            return 1;
        }

        double radius = stod(argv[3]);
        double area = krug(radius);
        cout << "Площадь круга: " << area << endl;
    } else if (operation == "triangle") {
        if (argc != 6) {
            cout << "Неверное количество операндов для операции 'triangle'. Используйте три операнда (стороны треугольника)." << endl;
            return 1;
        }

        double side1 = stod(argv[3]);
        double side2 = stod(argv[4]);
        double side3 = stod(argv[5]);
        double area = treug(side1, side2, side3);
        cout << "Площадь треугольника: " << area << endl;
    } else {
        cout << "Неизвестная операция: " << operation << endl;
        return 1;
    }

    return 0;
}