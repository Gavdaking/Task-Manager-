#ifndef TASK_H
#define TASK_H

#include <iostream>
using namespace std;

// Task structure to store task details
struct Task {

    string desc_GJ;  // Task description

    string pri_GJ;   // Priority (High, Medium, Low)

    string date_GJ;  // Due date

    bool completed;  // Task completion 

    Task* next;      // Pointer to next task

    // Constructor 

    Task(string desc, string pri, string date)
        : desc_GJ(desc), pri_GJ(pri), date_GJ(date), completed(false), next(nullptr) {}
        
};

#endif
