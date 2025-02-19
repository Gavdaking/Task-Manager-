#include "TaskList.h"

// Show the menu options
void showMenu()
 {
    cout << "\nTask Manager\n";
    cout << "1. Add Task\n";
    cout << "2. Remove Completed Task\n";
    cout << "3. Mark Task as Complete\n";
    cout << "4. Search Task\n";
    cout << "5. Display All Tasks\n";
    cout << "6. Filter by Priority\n";
    cout << "7. Show Task Count\n";
    cout << "8. Exit\n";
    cout << "Enter choice: ";
}

int main() 
{
    TaskList taskList;
    int choice;
    string desc_GJ, pri_GJ, date_GJ;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
            case 1:
                cout << "Enter description: ";
                getline(cin, desc_GJ);
                cout << "Enter priority (High/Medium/Low): ";
                cin >> pri_GJ;
                cout << "Enter due date (YYYY-MM-DD): ";
                cin >> date_GJ;
                taskList.addTask(desc_GJ, pri_GJ, date_GJ);
                break;
            case 2:
                taskList.removeCompletedTask();
                break;
            case 3:
                cout << "Enter task description to mark complete: ";
                getline(cin, desc_GJ);
                taskList.markTaskComplete(desc_GJ);
                break;
            case 4:
                cout << "Enter task description to search: ";
                getline(cin, desc_GJ);
                taskList.searchTask(desc_GJ);
                break;
            case 5:
                taskList.displayTasks();
                break;
            case 6:
                cout << "Enter priority to filter (High/Medium/Low): ";
                cin >> pri_GJ;
                taskList.filterByPriority(pri_GJ);
                break;
            case 7:
                cout << "Total tasks: " << taskList.countTasks() << endl;
                break;
            case 8:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
    
}
