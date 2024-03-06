//
// Write a C++ program to generate bank account numbers for each new account created, utilizing a static variable.
// The program should prompt the user to input the account name and initial deposit amount.
// The deposit amount cannot be a negative number and account balance cannot go below zero.
//


#include <iostream>
#include <string>
#include <vector>

class Account {
private:
    static int nextAccountNumber;
    int accountNumber;
    std::string name;
    double balance;

public:
    Account() { accountNumber = nextAccountNumber++; }

    void setName(const std::string& n) { name = n; }
    void setBalance(double b) { balance = b; }

    int getAccountNumber() const { return accountNumber; } // Public getter function

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            std::cout << "Invalid deposit amount." << std::endl;
    }

    void withdraw(double amount) {
        if (balance >= amount && amount > 0)
            balance -= amount;
        else if (amount <= 0)
            std::cout << "Invalid withdrawal amount." << std::endl;
        else
            std::cout << "Insufficient balance." << std::endl;
    }

    friend std::istream& operator>>(std::istream& in, Account& acc);
    friend std::ostream& operator<<(std::ostream& out, const Account& acc);
};

int Account::nextAccountNumber = 1000;

std::istream& operator>>(std::istream& in, Account& acc) {
    std::cout << "Enter account name: ";
    std::string name;
    in >> name;
    acc.setName(name);

    double balance;
    do {
        std::cout << "Enter initial balance (must be non-negative): ";
        in >> balance;
        if (balance < 0)
            std::cout << "Initial balance cannot be negative. Please try again." << std::endl;
    } while (balance < 0);
    acc.setBalance(balance);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Account& acc) {
    out << "\n Account Number: " << acc.accountNumber << "\n Account Name: " << acc.name << "\n Balance: " << acc.balance << "\n";
    return out;
}

int main() {
    std::vector<Account> accounts;

    int choice;
    while (true) {
        std::cout << "\n1. Create a new account\n2. Display all accounts\n3. Deposit\n4. Withdraw\n5. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Account newAccount;
                std::cin >> newAccount;
                accounts.push_back(newAccount);
                break;
            }
            case 2:
                if (accounts.empty()) {
                    std::cout << "No accounts created yet." << std::endl;
                } else {
                    std::cout << "\n--- All Accounts ---\n";
                    for (const auto& account : accounts) {
                        std::cout << account << std::endl;
                    }
                }
                break;
            case 3: {
                int accountNumber;
                double depositAmount;
                std::cout << "Enter account number to deposit into: ";
                std::cin >> accountNumber;
                bool accountFound = false;
                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        accountFound = true;
                        std::cout << "Enter deposit amount: ";
                        std::cin >> depositAmount;
                        account.deposit(depositAmount);
                        break;
                    }
                }
                if (!accountFound)
                    std::cout << "Account not found." << std::endl;
                break;
            }
            case 4: {
                int accountNumber;
                double withdrawAmount;
                std::cout << "Enter account number to withdraw from: ";
                std::cin >> accountNumber;
                bool accountFound = false;
                for (auto& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        accountFound = true;
                        std::cout << "Enter withdrawal amount: ";
                        std::cin >> withdrawAmount;
                        account.withdraw(withdrawAmount);
                        break;
                    }
                }
                if (!accountFound)
                    std::cout << "Account not found." << std::endl;
                break;
            }
            case 5:
                std::cout << "Goodbye!\n" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}



/*
1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:2

No accounts created yet.

1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:1

Enter account name:Swapnil

Enter initial balance (must be non-negative):5000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:1

Enter account name:Arpan

Enter initial balance (must be non-negative):-50

Initial balance cannot be negative. Please try again.
Enter initial balance (must be non-negative):5000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:2


--- All Accounts ---

 Account Number: 1000
 Account Name: Swapnil
 Balance: 5000


 Account Number: 1001
 Account Name: Arpan
 Balance: 5000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:3

Enter account number to deposit into:5000

Account not found.

1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:3

Enter account number to deposit into:1000

Enter deposit amount:5000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:4

Enter account number to withdraw from:10001

Account not found.

1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:4

Enter account number to withdraw from:1001

Enter withdrawal amount:6000

Insufficient balance.

1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:4

Enter account number to withdraw from:1001

Enter withdrawal amount:3000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:2


--- All Accounts ---

 Account Number: 1000
 Account Name: Swapnil
 Balance: 10000


 Account Number: 1001
 Account Name: Arpan
 Balance: 2000


1. Create a new account
2. Display all accounts
3. Deposit
4. Withdraw
5. Quit
Enter your choice:5

Goodbye!

*/