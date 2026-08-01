#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to add a task
void addTask(vector<string>& tasks)
{
    string task;

    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);

    tasks.push_back(task);

    cout << "Task added: \"" << task << "\"" << endl;
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "Your task list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    for (int i = 0; i < tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks)
{
    if (tasks.empty())
    {
        cout << "There are no tasks to delete." << endl;
        return;
    }

    // Display tasks first
    viewTasks(tasks);

    int taskNumber;

    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    // Check whether the task number is valid
    if (taskNumber < 1 || taskNumber > tasks.size())
    {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string deletedTask = tasks[taskNumber - 1];

    tasks.erase(tasks.begin() + (taskNumber - 1));

    cout << "Task \"" << deletedTask << "\" has been removed." << endl;
}

// Function to display the menu
void displayMenu()
{
    cout << "\n============================" << endl;
    cout << "       TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main()
{
    vector<string> tasks;
    int choice;

    // Keep showing the menu until the user chooses 4
    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTask(tasks);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                deleteTask(tasks);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Error: Invalid choice. Please choose a number "
                     << "from 1 to 4." << endl;
        }
    }

    return 0;
}

