#include "TaskList.h"

// Constructor initializes an empty list
TaskList::TaskList() : head(nullptr), tail(nullptr) {}

// Destructor to free memory
TaskList::~TaskList() 
{
    while (head) 
    {
        Task* temp = head;
        head = head->next;
        delete temp;
    }

}

// Add task with priority-based insertion
void TaskList::addTask(string desc_GJ, string pri_GJ, string date_GJ) 
{
    Task* newTask = new Task(desc_GJ, pri_GJ, date_GJ);

    // Insert at head if list is empty or higher priority
    if (!head || (pri_GJ == "High") || (pri_GJ == "Medium" && head->pri_GJ == "Low")) 
    
    {
        newTask->next = head;
        head = newTask;
        if (!tail) tail = newTask;
    } else {
        Task* temp = head;
        while (temp->next && temp->next->pri_GJ != "Low") 
        {
            temp = temp->next;
        }
        newTask->next = temp->next;
        temp->next = newTask;
        if (!newTask->next) tail = newTask;
    }
}

// Remove first completed task from the list
void TaskList::removeCompletedTask() 
{

    if (!head) 
    {
        cout << "No tasks to remove.\n";
        return;
    }
    Task* temp = head;
    Task* prev = nullptr;

    while (temp) 
    {
        if (temp->completed) 
        {
            if (prev) prev->next = temp->next;
            else head = temp->next;
            delete temp;
            cout << "Completed task removed.\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }
    cout << "No completed tasks found.\n";
}

// Mark a task as complete
void TaskList::markTaskComplete(string desc_GJ) {
    Task* temp = head;
    while (temp) {
        if (temp->desc_GJ == desc_GJ) {
            temp->completed = true;
            cout << "Task marked as complete.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Task not found.\n";
}

// Search for a task by description
void TaskList::searchTask(string desc_GJ) 
{
    Task* temp = head;
    while (temp) 
    {
        if (temp->desc_GJ == desc_GJ) 
        {
            cout << "Task Found: " << temp->desc_GJ << " | Priority: " 
                 << temp->pri_GJ << " | Due: " << temp->date_GJ 
                 << " | " << (temp->completed ? "Completed" : "Incomplete") << endl;
            return;
        }

        temp = temp->next;
    }
    cout << "Task not found.\n";
}

// Display all tasks
void TaskList::displayTasks() 

{
    if (!head) 
    {
        cout << "No tasks available.\n";
        return;
    }
    Task* temp = head;
    while (temp) 
    {
        cout << temp->desc_GJ << " | Priority: " << temp->pri_GJ
             << " | Due: " << temp->date_GJ << " | "
             << (temp->completed ? "Completed" : "Incomplete") << endl;
        temp = temp->next;
    }
}

// Show tasks with a specific priority
void TaskList::filterByPriority(string pri_GJ) 
{
    Task* temp = head;
    bool found = false;
    while (temp) 
    {
        if (temp->pri_GJ == pri_GJ) 
        {
            cout << temp->desc_GJ << " | Due: " << temp->date_GJ << " | "
                 << (temp->completed ? "Completed" : "Incomplete") << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No tasks with " << pri_GJ << " priority found.\n";
}

// Count total tasks
int TaskList::countTasks() 
{
    int count = 0;
    Task* temp = head;
    while (temp) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}
