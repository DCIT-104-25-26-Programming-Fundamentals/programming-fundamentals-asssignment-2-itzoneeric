#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function for addition
double add(double a, double b)
{
    return a + b;
}

// Function for subtraction
double subtract(double a, double b)
{
    return a - b;
}

// Function for multiplication
double multiply(double a, double b)
{
    return a * b;
}

// Function for division
double divide(double a, double b)
{
    return a / b;
}

// Function for modulus
int modulus(int a, int b)
{
    return a % b;
}

// Function for exponentiation
double exponentiate(double a, double b)
{
    return pow(a, b);
}

// Function to display the menu
void displayMenu()
{
    cout << "\n============================" << endl;
    cout << "       SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main()
{
    int choice;

    cout << fixed << setprecision(2);

    while (true)
    {
        displayMenu();
        cin >> choice;

        // Check for invalid menu choices
        if (choice < 1 || choice > 7)
        {
            cout << "Error: Invalid choice. Please select a number "
                 << "from 1 to 7." << endl;
            continue;
        }

        // Quit
        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        double firstNumber;
        double secondNumber;

        cout << "Enter first number : ";
        cin >> firstNumber;

        cout << "Enter second number: ";
        cin >> secondNumber;

        switch (choice)
        {
            case 1:
                cout << "Result: " << firstNumber << " + "
                     << secondNumber << " = "
                     << add(firstNumber, secondNumber) << endl;
                break;

            case 2:
                cout << "Result: " << firstNumber << " - "
                     << secondNumber << " = "
                     << subtract(firstNumber, secondNumber) << endl;
                break;

            case 3:
                cout << "Result: " << firstNumber << " * "
                     << secondNumber << " = "
                     << multiply(firstNumber, secondNumber) << endl;
                break;

            case 4:
                if (secondNumber == 0)
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    cout << "Result: " << firstNumber << " / "
                         << secondNumber << " = "
                         << divide(firstNumber, secondNumber) << endl;
                }
                break;

            case 5:
            {
                int firstInt = static_cast<int>(firstNumber);
                int secondInt = static_cast<int>(secondNumber);

                if (secondInt == 0)
                {
                    cout << "Error: Cannot calculate modulus by zero."
                         << endl;
                }
                else
                {
                    cout << "Result: " << firstInt << " % "
                         << secondInt << " = "
                         << modulus(firstInt, secondInt) << endl;
                }
                break;
            }

            case 6:
                cout << "Result: " << firstNumber << " ^ "
                     << secondNumber << " = "
                     << exponentiate(firstNumber, secondNumber) << endl;
                break;
        }
    }

    return 0;
}