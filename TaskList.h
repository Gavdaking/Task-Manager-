#ifndef TASKLIST_H
#define TASKLIST_H

#include "Task.h"

// TaskList class 
class TaskList {

private:

    Task* head;
    Task* tail;

public:

    TaskList();  // Constructor
    ~TaskList(); // Destructor

    void addTask(string desc_GJ, string pri_GJ, string date_GJ); // Insert task with priority

    void removeCompletedTask(); // Remove first completed task

    void markTaskComplete(string desc_GJ); // Mark a task as complete

    void searchTask(string desc_GJ); // Search for a task by description

    void displayTasks(); // Display all tasks

    void filterByPriority(string pri_GJ); // Show tasks with a specific priority
    
    int countTasks(); // Get total number of tasks


};

#endif
