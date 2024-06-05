//
// Searching, sorting using stl vector and concept of lambda function using student class
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
    string name;
    int id;
public:
    Student(string name, int id) : name(name), id(id) {}

    string getName() const { return name; }
    int getID() const { return id; }

    friend ostream& operator<<(ostream& os, const Student& s);
};

ostream& operator<<(ostream& os, const Student& s) {
    os << "Name: " << s.name << endl << "ID: " << s.id << endl;
    return os;
}

int main() {
    vector<Student> vs;
    char choice;

    do {
        string name;
        int id;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;

        vs.push_back(Student(name, id));

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << endl << "List of Students: " << endl;
    for (const Student& s : vs) {
        cout << s;
    }
    cout << endl;

    sort(vs.begin(), vs.end(), [](const Student &a, const Student &b) { return a.getID() < b.getID(); });
    cout << "List of Students sorted by ID: " << endl;
    for (const Student& s : vs) {
        cout << s;
    }
    cout << endl;

    sort(vs.begin(), vs.end(), [](const Student &a, const Student &b) { return a.getName() < b.getName(); });
    cout << "List of Students sorted by Name: " << endl;
    for (const Student& s : vs) {
        cout << s;
    }
    cout << endl;

    int targetId;
    cout << "Enter the student ID to search: ";
    cin >> targetId;
    auto it = find_if(vs.begin(), vs.end(), [targetId](const Student &s) { return s.getID() == targetId; });
    if (it != vs.end()) {
        cout << "Student found:" << endl;
        cout << *it;
    } else {
        cout << "Student not found." << endl;
    }
    cout << endl;

    string targetName;
    cout << "Enter the student name to search: ";
    cin >> targetName;
    it = find_if(vs.begin(), vs.end(), [targetName](const Student &s) { return s.getName() == targetName; });
    if (it != vs.end()) {
        cout << "Student found:" << endl;
        cout << *it;
    } else {
        cout << "Student not found." << endl;
    }

    return 0;
}
