//
// user input users first middle and last name and greet the user in c++
// count the number of character in the name and display it
// also count the vowels
//

#include <iostream>
#include <string>
#include <algorithm>

int countVowels(const std::string& name) {
    int count = 0;
    for (char c : name) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
            }
    }
    return count;
}

int main() {
    std::string firstName, middleName, lastName;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;

    std::cout << "Enter your middle name: ";
    std::cin >> middleName;

    std::cout << "Enter your last name: ";
    std::cin >> lastName;

    std::string fullName = firstName + " " + middleName + " " + lastName;

    std::cout << "Hello, " << fullName << "!" << std::endl;

    int nameLength = fullName.length();
    int vowelCount = countVowels(fullName);

    int spaceCount = std::count(fullName.begin(), fullName.end(), ' ');
    nameLength -= spaceCount;

    std::cout << "Your name has " << nameLength << " characters." << std::endl;
    std::cout << "Your name has " << vowelCount << " vowels." << std::endl;

    return 0;
}

/*
        Output
Enter your first name:Swapnil

Enter your middle name:De

Enter your last name:Sarkar

Hello, Swapnil De Sarkar!
Your name has 15 characters.
Your name has 5 vowels.

 */