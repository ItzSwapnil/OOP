//
// Write a C++ program to implement a friend class and a friend function.
// And overload the insertion operators
//

#include <iostream>

class B;

class A {
private:
    int dataA;

public:
    A() : dataA(100) {}

    friend std::ostream& operator<<(std::ostream& os, const A& objA);
};

class B {
private:
    int dataB;

public:
    B() : dataB(90) {}

    friend std::ostream& operator<<(std::ostream& os, const B& objB);
};

std::ostream& operator<<(std::ostream& os, const A& objA) {
    os << "Data from class A: " << objA.dataA;
    return os;
}

std::ostream& operator<<(std::ostream& os, const B& objB) {
    os << "Data from class B: " << objB.dataB;
    return os;
}

int main() {
    A objA;
    B objB;

    std::cout << objA << std::endl;
    std::cout << objB << std::endl;

    return 0;
}



/*
Output:

Data from class A: 100
Data from class B: 90

 */