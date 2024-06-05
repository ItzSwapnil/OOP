//
// Searching, sorting using stl vector and concept of lambda function using student class
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Student {
    string name;
    int id;
public:
    Student(string name, int id) : name(std::move(name)), id(id) {}

    [[nodiscard]] string getName() const { return name; }
    [[nodiscard]] int getID() const { return id; }

    friend ostream& operator<<(ostream& os, const Student& s);
};

ostream& operator<<(ostream& os, const Student& s) {
    os << "Name: " << s.name << endl << "ID: " << s.id << endl;
    return os;
}

void addStudent(vector<Student>& vs) {
    string name;
    int id;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter student ID: ";
    cin >> id;

    vs.emplace_back(std::move(name), id);
}

void displayStudents(const vector<Student>& vs) {
    for (const Student& s : vs) {
        cout << s;
    }
}

void sortByID(vector<Student>& vs) {
    sort(vs.begin(), vs.end(), [](const Student &a, const Student &b) { return a.getID() < b.getID(); });
    cout << "List of Students sorted by ID: " << endl;
    displayStudents(vs);
    cout << endl;
}

void sortByName(vector<Student>& vs) {
    sort(vs.begin(), vs.end(), [](const Student &a, const Student &b) { return a.getName() < b.getName(); });
    cout << "List of Students sorted by Name: " << endl;
    displayStudents(vs);
    cout << endl;
}

void searchByID(const vector<Student>& vs) {
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
}

void searchByName(const vector<Student>& vs) {
    string targetName;
    cout << "Enter the student name to search: ";
    cin.ignore();
    getline(cin, targetName);
    auto it = find_if(vs.begin(), vs.end(), [targetName](const Student &s) { return s.getName() == targetName; });
    if (it != vs.end()) {
        cout << "Student found:" << endl;
        cout << *it;
    } else {
        cout << "Student not found." << endl;
    }
    cout << endl;
}

int main() {
    vector<Student> vs;
    int choice;

    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Add more students" << endl;
        cout << "2. Sort students by ID (ascending)" << endl;
        cout << "3. Sort students by Name (ascending)" << endl;
        cout << "4. Search for a student by ID" << endl;
        cout << "5. Search for a student by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(vs);
                break;
            case 2:
                sortByID(vs);
                break;
            case 3:
                sortByName(vs);
                break;
            case 4:
                searchByID(vs);
                break;
            case 5:
                searchByName(vs);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


/*
 Output:

What would you like to do?
1. Add more students
2. Sort students by ID (ascending)
3. Sort students by Name (ascending)
4. Search for a student by ID
5. Search for a student by Name
6. Exit
Enter your choice:1

Enter student name:A

Enter student ID:56

        ||
Enter your choice:1

Enter student name:B

Enter student ID:11

         ||
Enter your choice:1

Enter student name:C

Enter student ID:99

        ||
Enter your choice:2

List of Students sorted by ID:
Name: B
ID: 11
Name: A
ID: 56
Name: C
ID: 99

        ||
Enter your choice:3

List of Students sorted by Name:
Name: A
ID: 56
Name: B
ID: 11
Name: C
ID: 99

        ||
Enter your choice:4

Enter the student ID to search:11

Student found:
Name: B
ID: 11

        ||
Enter your choice:5

Enter the student name to search:B

Student found:
Name: B
ID: 11

        ||
Enter your choice:6

Exiting...

*/