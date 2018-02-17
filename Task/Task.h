/***Task.h**********************************************************************
 Programmer: Brenna Olson
 Description: Sort a file of Task objects by type and then jobId
 Operations:
    Function members:
        Task (constructor): Initialize Task object that only needs CPU
        Task (constructor): Initialize Task object that needs CPU and disk space
        Task (constructor): Initialize Task object that needs CPU and I/O 
                            devices
        getJobId: Get Task object's job id
        getType: Get Task object's type
        display: Put contents of Task object into output stream
        read: Put contents of Task object into input stream
 
    Other functions:
        operator<<: Put contents of Task object into output stream
        operator>>: Put contents of Task object into input stream
        operator<: Determine if task1's jobId is < task2's jobId
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#ifndef TASK_H
#define TASK_H


#include <iostream>
#include <string>
using namespace std;

class Task {
public:
    
    
    //**************************************************************************
    // Function: Task (constructor)
    //
    // Purpose: Initialize Task object that only needs CPU
    //
    // PreCondition: None
    //
    // PostCondition: type initialized to 1; jobId initialized to passed-in
    //                value
    //**************************************************************************
    
    Task(int job) {
        type = 1;
        jobId = job;
    }
    
    
    //**************************************************************************
    // Function: Task (constructor)
    //
    // Purpose: Initialize Task object that needs CPU and disk space
    //
    // PreCondition: None
    //
    // PostCondition: type initialized to s; jobId, spaceAmount, and drive
    //                initialized to passed-in values
    //**************************************************************************
    
    Task(int job, int space, char driveLetter) {
        type = 2;
        jobId = job;
        spaceAmount = space;
        drive = driveLetter;
    }
    
    
    //**************************************************************************
    // Function: Task (constructor)
    //
    // Purpose: Initialize Task object that needs CPU and I/O devices
    //
    // PreCondition: None
    //
    // PostCondition: type initialized to 1; jobId, deviceDesignator, and
    //                printerName initialized to passed-in value
    //**************************************************************************
    
    Task(int job, int designator, string name) {
        type = 3;
        jobId = job;
        deviceDesignator = designator;
        printerName = name;
    }
    
    
    //**************************************************************************
    // Function: getJobId
    //
    // Purpose: Get Task object's job id
    //
    // PreCondition: None
    //
    // PostCondition: Task object's job id returned
    //**************************************************************************
    
    int getJobId() const {
        return jobId;
    }
    
    
    //**************************************************************************
    // Function: getType
    //
    // Purpose: Get Task object's type
    //
    // PreCondition: None
    //
    // PostCondition: Task object's type returned
    //**************************************************************************
    
    int getType() const {
        return type;
    }
    
    
    //**************************************************************************
    // Function: display
    //
    // Purpose: Put contents of Task object into output stream
    //
    // PreCondition: None
    //
    // PostCondition: Contents of Task object in output stream
    //**************************************************************************
    
    void display(ostream &out) const;
    
    
    //**************************************************************************
    // Function: read
    //
    // Purpose: Put contents of Task object into input stream
    //
    // PreCondition: None
    //
    // PostCondition: Contents of Task object in input stream
    //**************************************************************************
    
    void read(istream &in);
    
private:
    int type;
    
    int jobId;
    
    int spaceAmount;
    char drive;
    
    int deviceDesignator;
    string printerName;
};


//******************************************************************************
// Function: operator<<
//
// Purpose: Put contents of Task object into output stream
//
// PreCondition: None
//
// PostCondition: Contents of Task object in output stream
//******************************************************************************

ostream &operator<<(ostream &out, const Task &c);


//******************************************************************************
// Function: operator>>
//
// Purpose: Put contents of Task object into input stream
//
// PreCondition: None
//
// PostCondition: Contents of Task object in input stream
//******************************************************************************

istream &operator>>(istream &in, Task &c);


//******************************************************************************
// Function: operator<
//
// Purpose: Determine if task1's jobId is < task2's jobId
//
// PreCondition: None
//
// PostCondition: true returned if <; otherwise, false returned
//******************************************************************************

bool operator<(const Task &task1, const Task &task2);


#endif
