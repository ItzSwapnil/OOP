//
// Fibonacci with recursion
//

#include <iostream>
using namespace std;

int fibonacci(int num)
{
    if (num == 1)
        return 0;
    else if (num == 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main()
{
    int num;
    cout << "Enter the number of terms: ";
    cin >> num;
    cout << "Fibonacci sequence: ";
    for (int i = 1; i <= num; ++i)
    {
        cout << fibonacci(i) << ", ";
    }
    return 0;
}

/*
        Output
Enter the number of terms:5

Fibonacci sequence: 0, 1, 1, 2, 3,

 */