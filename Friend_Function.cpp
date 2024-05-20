//
// Write a C++ program to implement a friend class and a friend function.
// And overload the friend function.
//

#include <iostream>

class B;

class A {
private:
    int dataA;

public:
    A() : dataA(100) {}

    friend void showData(A objA, B objB);
    friend void showData(A& objA);
};

class B {
private:
    int dataB;

public:
    B() : dataB(90) {}

    friend void showData(A objA, B objB);
};

void showData(A objA, B objB) {
    std::cout << "Data from class A: " << objA.dataA << std::endl;
    std::cout << "Data from class B: " << objB.dataB << std::endl;
}

void showData(A& objA) {
    objA.dataA += 50;
    std::cout << "Overloaded data from class A: " << objA.dataA << std::endl;
}

int main() {
    A objA;
    B objB;

    showData(objA, objB);
    showData(objA);

    return 0;
}


/*
Output:

Data from class A: 100
Data from class B: 90
Overloaded data from class A: 150

 */