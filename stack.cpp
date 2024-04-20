//
// Create a stack in C++ also include push, pop , underflow and overflow (exception handling) with user input
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

class Stack {
    private:
        int *arr;
        int top;
        int size;

    public:
        Stack(int size) {
            this->size = size;
            this->arr = new int[size];
            this->top = -1;
        }

        ~Stack() {
            delete[] arr;
        }

        void push(int value) {
            if (top == size - 1) {
                throw Overflow();
            }
            arr[++top] = value;
        }

        int pop() {
            if (top == -1) {
                throw Underflow();
            }
            return arr[top--];
        }

        void display() {
            if (top == -1) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack contents: ";
                for (int i = 0; i <= top; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    Stack stack(size);
    char choice;
    int value;

    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            try {
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                cout << "Pushed value: " << value << endl;
                stack.display();
            } catch (const exception& e) {
                cerr << "\n Caught exception: " << e.what() << endl;
            }
            break;
            case '2':
                try {
                    cout << "Popped value: " << stack.pop() << endl;
                } catch (const exception& e) {
                    cerr << "\n Caught exception: " << e.what() << endl;
                }
                break;

            case '3':
                stack.display();
                break;

            case '4':
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}