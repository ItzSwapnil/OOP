//
// Write a C++ program to implement Friend class and function
//
#include <iostream>
#include <iostream>

class A {
public:
    int x = 10;
    void print_x() const {
        std::cout << x << std::endl;
    }
};

class B {
public:
    int y = 20;
    void print_y() const {
        std::cout << y << std::endl;
    }
};

class Friend {
public:
    friend void print_xy(const A&, const B&);
};

void print_xy(const A& a, const B& b) {
    a.print_x();
    b.print_y();
}

int main() {
    const A a;
    const B b;
    Friend f;

    print_xy(a, b);

    return 0;
}