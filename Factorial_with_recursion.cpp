//
// Factorial with recursion
//
#include <iostream>
using namespace std;

unsigned int factorial(unsigned int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
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