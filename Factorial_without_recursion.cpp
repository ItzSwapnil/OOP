//
// Factorial without recursion
//
#include <iostream>
using namespace std;

unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}


/*
        Output
Enter a positive integer:5

Factorial of 5 is 120

 */