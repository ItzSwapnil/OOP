//
// Write a C++ program to find area of a triangle, rectangle, circle
//

#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    float base;
    float height;
public:
    Triangle(float _base, float _height) : base(_base), height(_height) {}

    float area() {
        return 0.5 * base * height;
    }
};

class Rectangle {
private:
    float length;
    float width;
public:
    Rectangle(float _length, float _width) : length(_length), width(_width) {}

    float area() {
        return length * width;
    }
};

class Circle {
private:
    float radius;
public:
    Circle(float _radius) : radius(_radius) {}

    float area() {
        return M_PI * radius * radius;
    }
};

int main() {
    int choice;

    do {
        cout << "Select the shape to find area:" << endl;
        cout << "1. Triangle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Circle" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> choice;

        switch(choice) {
            case 1: {
                float base, height;
                cout << "Enter base and height of the triangle: ";
                cin >> base >> height;
                Triangle triangle(base, height);
                cout << "Area of the triangle is: " << triangle.area() << endl;
                break;
            }
            case 2: {
                float length, width;
                cout << "Enter length and width of the rectangle: ";
                cin >> length >> width;
                Rectangle rectangle(length, width);
                cout << "Area of the rectangle is: " << rectangle.area() << endl;
                break;
            }
            case 3: {
                float radius;
                cout << "Enter radius of the circle: ";
                cin >> radius;
                Circle circle(radius);
                cout << "Area of the circle is: " << circle.area() << endl;
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}


/*
Output:

Select the shape to find area:
1. Triangle
2. Rectangle
3. Circle
4. Exit
Enter your choice (1/2/3/4):1

Enter base and height of the triangle:5 6

Area of the triangle is: 15
Select the shape to find area:
1. Triangle
2. Rectangle
3. Circle
4. Exit
Enter your choice (1/2/3/4):2

Enter length and width of the rectangle:3 4

Area of the rectangle is: 12
Select the shape to find area:
1. Triangle
2. Rectangle
3. Circle
4. Exit
Enter your choice (1/2/3/4):3

Enter radius of the circle:6

Area of the circle is: 113.097
Select the shape to find area:
1. Triangle
2. Rectangle
3. Circle
4. Exit
Enter your choice (1/2/3/4):4

Exiting...

*/