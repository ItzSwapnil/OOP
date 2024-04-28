//
// Write a C++ program to implement Friend class and function
//
#include <iostream>

class B;

class A {
private:
    int dataA;

public:
    A() : dataA(100) {}

    friend void showData(A objA, B objB);

    friend class B;
};

class B {
private:
    int dataB;

public:
    B() : dataB(90) {}

    friend void showData(A objA, B objB) {
        std::cout << "Data from class A: " << objA.dataA << std::endl;
        std::cout << "Data from class B: " << objB.dataB << std::endl;
    }
};

int main() {
    A objA;
    B objB;

    showData(objA, objB);

    return 0;
}

/*
Output:

Data from class A: 100
Data from class B: 90

 */