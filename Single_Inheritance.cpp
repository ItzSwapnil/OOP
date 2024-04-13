//
// Write a C++ program to create Single Inheritance using class in cpp
//

#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

int main() {
    Dog pet;
    pet.eat();
    pet.bark();

    return 0;
}


/*
    Output:
Animal is eating.
Dog is barking.

*/