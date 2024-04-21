//
//  Write a C++ program to implement a linked list
//

#include <iostream>
#include <sstream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " into the linked list." << endl;
    }

    void remove(int value) {
        if (head == nullptr) {
            cout << "Linked list is empty. Deletion failed." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the linked list." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found in the linked list. Deletion failed." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Deleted " << value << " from the linked list." << endl;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked list: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;
    string input;

    do {
        cout << "\nChoose an option:" << endl;
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value(s) to insert separated by space: ";
                cin.ignore();
                getline(cin, input);
                {
                    stringstream ss(input);
                    while (ss >> value) {
                        list.insert(value);
                    }
                }
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                list.display();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while(choice != 4);

    return 0;
}


/*
    output:
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:1

Enter value(s) to insert separated by space:5 6 9 8 2 3

Inserted 5 into the linked list.
Inserted 6 into the linked list.
Inserted 9 into the linked list.
Inserted 8 into the linked list.
Inserted 2 into the linked list.
Inserted 3 into the linked list.

Choose an option:
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:3

Linked list: 5 6 9 8 2 3

Choose an option:
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:2

Enter value to delete:2

Deleted 2 from the linked list.

Choose an option:
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:3

Linked list: 5 6 9 8 3

Choose an option:
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:4

Exiting program...

*/
