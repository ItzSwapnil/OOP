//
// Fibonacci without recursion
//
#include <iostream>
using namespace std;

void fibonacci(int num)
{
    int t1 = 0, t2 = 1, nextTerm = 0;
    for (int i = 1; i <= num; ++i)
    {
        if (i == 1)
        {
            cout << t1 << ", ";
            continue;
        }
        if (i == 2)
        {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << ", ";
    }
}

int main()
{
    int num;
    cout << "Enter the number of terms: ";
    cin >> num;
    fibonacci(num);
    return 0;
}


/*
        Output
Enter the number of terms:5

Fibonacci sequence: 0, 1, 1, 2, 3,

 */