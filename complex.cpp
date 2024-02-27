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
        return Complex(real * other.real, imag * other.imag);
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

    cout << "The sum of the two complex numbers is: ";
    sum.display();

    cout << "The sub of the two complex numbers is: ";
    sub.display();

    cout << "The product of the two complex numbers is: ";
    mul.display();


    return 0;
}

/*
                Output
Enter the real and imaginary parts of the second complex number:5 -1

The sum of the two complex numbers is: 10 - 4i
The sub of the two complex numbers is: 0 - 2i
The product of the two complex numbers is: 25 + 3i

 */