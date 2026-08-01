#include <iostream>
using namespace std;

bool isPrime(int number)
{
    // Numbers less than 2 are not prime
    if (number < 2)
    {
        return false;
    }

    // Check if number has any divisor other than 1 and itself
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
    {
        cout << number << " is a prime number." << endl;
    }
    else
    {
        cout << number << " is NOT a prime number." << endl;
    }

    return 0;
}

