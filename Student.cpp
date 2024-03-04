//
// Write a C++ code to stores student information including
// name, ID, quiz score, and ESA score,
// and includes an option to delete a student record based on user input.
//

#include <iostream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::string name;
    int quizScore;
    int esaScore;
};

void addStudent(std::vector<Student>& students) {
    Student newStudent;
    std::cout << "Enter the student's ID: ";
    std::cin >> newStudent.id;
    std::cout << "Enter the student's name: ";
    std::cin.ignore();
    std::getline(std::cin, newStudent.name);
    std::cout << "Enter the student's quiz score: ";
    std::cin >> newStudent.quizScore;
    std::cout << "Enter the student's ESA score: ";
    std::cin >> newStudent.esaScore;
    students.push_back(newStudent);
}

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    for (const auto& student : students) {
        std::cout << "ID: " << student.id << "\n";
        std::cout << "Name: " << student.name << "\n";
        std::cout << "Quiz score: " << student.quizScore << "\n";
        std::cout << "ESA score: " << student.esaScore << "\n";
        std::cout << "--------------------\n";
    }
}

void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Enter the student's ID to delete: ";
    std::cin >> id;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            std::cout << "Student deleted.\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

int main() {
    std::vector<Student> students;
    int choice;
    do {
        std::cout << "\n1. Add student\n";
        std::cout << "2. Display students\n";
        std::cout << "3. Delete student\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                deleteStudent(students);
                break;
            case 4:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);
    return 0;
}


/*
            Output


1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:1

Enter the student's ID:4031

Enter the student's name:Swapnil

Enter the student's quiz score:20

Enter the student's ESA score:60


1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:1

Enter the student's ID:4036

Enter the student's name:Arpan

Enter the student's quiz score:15

Enter the student's ESA score:55


1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:2

ID: 4031
Name: Swapnil
Quiz score: 20
ESA score: 60
--------------------
ID: 4036
Name: Arpan
Quiz score: 15
ESA score: 55
--------------------

1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:3

Enter the student's ID to delete:4036

Student deleted.

1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:2

ID: 4031
Name: Swapnil
Quiz score: 20
ESA score: 60
--------------------

1. Add student
2. Display students
3. Delete student
4. Quit
Enter your choice:4

Goodbye!


 */
