//
// write a C++ program to perform inheritance definition in the code.
//

#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(string _name) : name(_name) {}
    void eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string _name) : Animal(_name) {}
    void bark() {
        cout << name << " is barking." << endl;
    }
};

int main() {
    string animalName, dogName;

    cout << "Enter name for an animal: ";
    cin >> animalName;

    cout << "Enter name for a dog: ";
    cin >> dogName;

    Animal animal(animalName);
    cout << endl << "Animal actions:" << endl;
    animal.eat();

    Dog dog(dogName);
    cout << endl << "Dog actions:" << endl;
    dog.eat();
    dog.bark();

    return 0;
}

/*
Output:
Enter name for an animal: Rob

Enter name for a dog:Jack


Animal actions:
Rob is eating.

Dog actions:
Jack is eating.
Jack is barking.

*/