#include <iostream>
#include <getopt.h>
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

void printUsage(const char* programName) {
    std::cout << "Использование: " << programName << " -o <операция>" << std::endl;
    std::cout << "Опции:" << std::endl;
    std::cout << "  -o <операция>   Выберите операцию: 'circle' (площадь круга) или 'triangle' (площадь треугольника)." << std::endl;
    std::cout << "  -s              Вывести справку по использованию." << std::endl;
}

int main(int argc, char* argv[]) {
    int option;
    std::string operation;

    while ((option = getopt(argc, argv, "o:s")) != -1) {
        switch (option) {
            case 'o':
                operation = optarg;
                break;
            case 's':
                printUsage(argv[0]);
                return 0;
        }
    }

    if (operation.empty()) {
        std::cout << "Выберите операцию с помощью параметра -o." << std::endl;
        return 1;
    }

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
        std::cout << "Неизвестная операция: " << operation << std::endl;
        return 1;
    }

    return 0;
}