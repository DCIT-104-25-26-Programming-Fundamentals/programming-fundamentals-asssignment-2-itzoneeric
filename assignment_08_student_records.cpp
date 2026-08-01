#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to store student information
struct Student
{
    string name;
    int id;
    vector<double> scores;
};

// Function to calculate the average score
double calculateAverage(const vector<double>& scores)
{
    if (scores.empty())
    {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores[i];
    }

    return sum / scores.size();
}

// Function to add a student
void addStudent(vector<Student>& students)
{
    Student student;

    cin.ignore();

    cout << "Student name: ";
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    // Check if the ID already exists
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == student.id)
        {
            cout << "Error: A student with this ID already exists."
                 << endl;
            return;
        }
    }

    int numberOfScores;

    cout << "How many scores? ";
    cin >> numberOfScores;

    if (numberOfScores < 0)
    {
        cout << "Error: Number of scores cannot be negative." << endl;
        return;
    }

    for (int i = 0; i < numberOfScores; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }

    students.push_back(student);

    cout << "Student \"" << student.name
         << "\" added successfully." << endl;
}

// Function to display all students
void displayAllStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << "\n================ STUDENT RECORDS ================\n";

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "ID: " << students[i].id << endl;

        cout << "Scores: ";

        if (students[i].scores.empty())
        {
            cout << "No scores";
        }
        else
        {
            for (int j = 0; j < students[i].scores.size(); j++)
            {
                cout << fixed << setprecision(2)
                     << students[i].scores[j];

                if (j < students[i].scores.size() - 1)
                {
                    cout << ", ";
                }
            }
        }

        cout << endl;

        cout << "Average: "
             << fixed << setprecision(2)
             << calculateAverage(students[i].scores)
             << endl;

        cout << "--------------------------------------------------"
             << endl;
    }
}

// Function to calculate the average for a specific student
void calculateStudentAverage(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }

    int id;

    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << fixed << setprecision(2);

            cout << students[i].name
                 << "'s average score: "
                 << calculateAverage(students[i].scores)
                 << endl;

            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

// Function to display the menu
void displayMenu()
{
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main()
{
    vector<Student> students;
    int choice;

    // Keep the program running until the user chooses Quit
    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayAllStudents(students);
                break;

            case 3:
                calculateStudentAverage(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Error: Invalid choice. "
                     << "Please choose a number from 1 to 4."
                     << endl;
        }
    }

    return 0;
}