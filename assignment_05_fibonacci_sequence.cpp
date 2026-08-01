#include <iostream>
using namespace std;

// Part A: Print the first N terms of the Fibonacci sequence
void printFibonacci(int n)
{
    int first = 0;
    int second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < n; i++)
    {
        cout << first;

        if (i < n - 1)
        {
            cout << " ";
        }

        int next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

// Part B: Check if a number is a Fibonacci number
bool isFibonacci(int number)
{
    int first = 0;
    int second = 1;

    // Check the first Fibonacci number
    if (number == 0)
    {
        return true;
    }

    while (first <= number)
    {
        if (first == number)
        {
            return true;
        }

        int next = first + second;
        first = second;
        second = next;
    }

    return false;
}

int main()
{
    int n;

    // Part A
    cout << "How many terms? ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number of terms must be a positive integer."
             << endl;
    }
    else
    {
        printFibonacci(n);
    }

    // Part B
    int number;

    cout << "\nEnter a number to check: ";
    cin >> number;

    if (isFibonacci(number))
    {
        cout << number << " is a Fibonacci number." << endl;
    }
    else
    {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}
