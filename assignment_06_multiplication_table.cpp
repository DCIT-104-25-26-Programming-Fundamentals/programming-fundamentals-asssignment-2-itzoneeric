#include <iostream>
using namespace std;

// Part A: Generate a multiplication table for one number
void printTable(int number)
{
    cout << "Multiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++)
    {
        cout << number << "  x  " << i << "  =  "
             << number * i << endl;
    }
}

// Part B: Generate multiplication tables from 1 to N
void printTablesUpToN(int n)
{
    for (int number = 1; number <= n; number++)
    {
        printTable(number);

        if (number < n)
        {
            cout << "---------------------------" << endl;
        }
    }
}

int main()
{
    int number;

    // Part A
    cout << "Enter a number: ";
    cin >> number;

    if (number <= 0)
    {
        cout << "Error: Number must be a positive integer." << endl;
        return 0;
    }

    printTable(number);

    // Part B
    int n;

    cout << "\nEnter N for tables from 1 to N: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: N must be a positive integer." << endl;
        return 0;
    }

    printTablesUpToN(n);

    return 0;
}

