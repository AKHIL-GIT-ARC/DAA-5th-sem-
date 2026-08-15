// Implementation and Time analysis of factorial program using 
// iterative and recursive method
#include <iostream>
using namespace std;

/*=========================================================
    Iterative Factorial

    Idea:
    Start with 1 and multiply it by every number from
    1 to n using a loop.

    Time Complexity:
    Best Case    : O(n)
    Average Case : O(n)
    Worst Case   : O(n)

    Space Complexity:
    O(1)
=========================================================*/

long long iterativeFactorial(int n)
{
    long long fact = 1;

    for(int i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}


/*=========================================================
    Recursive Factorial

    Idea:
    Factorial is calculated by repeatedly calling the
    same function with n - 1 until the base case is reached.

    Time Complexity:
    Best Case    : O(n)
    Average Case : O(n)
    Worst Case   : O(n)

    Space Complexity:
    O(n)

    Note:
    Recursive method uses function call stack.
=========================================================*/

long long recursiveFactorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * recursiveFactorial(n - 1);
}


/*======================= Main =======================*/

int main()
{
    int n, ch;
    long long ans;

    cout << "Enter a number: ";
    cin >> n;

    cout << "\nFactorial Methods";
    cout << "\n1. Iterative Method";
    cout << "\n2. Recursive Method";

    cout << "\n\nEnter your choice: ";
    cin >> ch;

    switch(ch)
    {
        case 1:
            ans = iterativeFactorial(n);
            cout << "\nFactorial = " << ans;
            break;

        case 2:
            ans = recursiveFactorial(n);
            cout << "\nFactorial = " << ans;
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}

/*
====================== SAMPLE OUTPUT ======================

Enter a number: 5

Factorial Methods
1. Iterative Method
2. Recursive Method

Enter your choice: 2

Factorial = 120

============================================================
*/