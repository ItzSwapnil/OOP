//
// Write a C++ program to find area of a triangle using class
//

#include <iostream>

class Triangle {
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    double base, height;
    std::cout << "Enter the base of the triangle: ";
    std::cin >> base;

    std::cout << "Enter the height of the triangle: ";
    std::cin >>height;

    Triangle triangle(base, height);
    std::cout << "Area of the triangle: " << triangle.getArea() << std::endl;

    return 0;
}


/*
        Output:
Enter the base of the triangle:5

Enter the height of the triangle:3

Area of the triangle: 7.5

*/