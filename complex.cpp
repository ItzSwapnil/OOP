//
// write a code in C++ to to perform addition substraction and multiplication
// of class complex number using 2 constructer
// one with 0 paremeter and one with a non zero parameter
// user user input
//

#include <iostream>


using namespace std;

class Complex {
private:
    int real;
    int imag;

public:

    Complex() {
        real = 0;
        imag = 0;
    }


    Complex(int r, int i) {
        real = r;
        imag = i;
    }


    Complex add(Complex other) {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex sub(Complex other) {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex mul(Complex other) {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }


    void display() {
        cout << real;
        if (imag >= 0) {
            cout << " + ";
        } else {
            cout << " - ";
        }
        cout << abs(imag) << "i" << endl;
    }

    int getReal() {
        return real;
    }

    int getImag() {
        return imag;
    }
};

int main() {
    int real1, imag1, real2, imag2;

    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin >> real1 >> imag1;

    Complex c1(real1, imag1);

    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin >> real2 >> imag2;

    Complex c2(real2, imag2);

    Complex sum = c1.add(c2);

    Complex sub = c1.sub(c2);

    Complex mul = c1.mul(c2);


    cout << "The sum of ";
    c1.display();
    cout << " and ";
    c2.display();
    cout << " is: ";
    sum.display();

    cout << "The subtraction of ";
    c1.display();
    cout << " and ";
    c2.display();
    cout << " is: ";
    sub.display();

    cout << "The multiplication of ";
    c1.display();
    cout << " and ";
    c2.display();
    cout << " is: ";
    mul.display();

    return 0;
}
/*
                Output
Enter the real and imaginary parts of the first complex number:5 6

Enter the real and imaginary parts of the second complex number:7 8

The sum of 5 + 6i
 and 7 + 8i
 is: 12 + 14i
The subtraction of 5 + 6i
 and 7 + 8i
 is: -2 - 2i
The multiplication of 5 + 6i
 and 7 + 8i
 is: -13 + 82i

 */