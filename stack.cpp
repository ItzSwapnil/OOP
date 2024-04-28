//
// Create a generic stack in C++ also include push, pop , underflow and overflow (Exception Handling) with user input
//


#include<iostream>
#include<string>

using namespace std;

class Overflow : public exception {
    private:
        string message;
    public:
        Overflow(string message = "Stack Overflow") : message(message) {}

        const char* what() const noexcept override {
            return message.c_str();
        }
};

class Underflow : public exception {
    private:
        string message;
    public:
        Underflow(string message = "Stack Underflow") : message(message) {}

        const char* what() const noexcept override {
            return message.c_str();
        }
};

template<typename T>
class Stack {
private:
    T* arr;
    int top;
    int size;

public:
    Stack(int size) {
        this->size = size;
        this->arr = new T[size];
        this->top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (top == size - 1) {
            throw std::overflow_error("Stack Overflow");
        }
        arr[++top] = value;
    }

    T pop() {
        if (top == -1) {
            throw std::underflow_error("Stack Underflow");
        }
        return arr[top--];
    }

    void display() {
        if (top == -1) {
            std::cout << "Stack is empty." << std::endl;
        } else {
            std::cout << "Stack contents: ";

            for (int i = 0; i <= top; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int size;
    std::cout << "Enter the size of the stack: ";
    std::cin >> size;
    Stack<int> stack(size);
    char choice;
    int value;

    while (true) {
        std::cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                try {
                    std::cout << "Enter the value to push: ";
                    std::cin >> value;
                    stack.push(value);
                    std::cout << "Pushed value: " << value << std::endl;
                    stack.display();
                } catch (const std::exception& e) {
                    std::cerr << "\n Caught exception: " << e.what() << std::endl;
                }
                break;
            case '2':
                try {
                    std::cout << "Popped value: " << stack.pop() << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "\n Caught exception: " << e.what() << std::endl;
                }
                break;

            case '3':
                stack.display();
                break;

            case '4':
                std::cout << "Exiting the program." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}


/*
Output:

E:\Projects\CLionProjects\OOP\cmake-build-debug\Stack.exe
Enter the size of the stack:2


1. Push
2. Pop
3. Display
4. Exit
Enter your choice:1

Enter the value to push:3

Pushed value: 3
Stack contents: 3

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:1

Enter the value to push:6

Pushed value: 6
Stack contents: 3 6

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:1

Enter the value to push:9

Pushed value:
 Caught exception: Stack Overflow

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2

Popped value: 6

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:3

Stack contents: 3

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:2

Popped value: 3

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:3

Stack is empty.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:2

Popped value:
 Caught exception: Stack Underflow

1. Push
2. Pop
3. Display
4. Exit
Enter your choice:4

Exiting the program.

Process finished with exit code 0

 */