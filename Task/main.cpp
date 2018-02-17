/***main.cpp********************************************************************
 Programmer: Brenna Olson
 Description: Sort a file of Task objects by type and then jobId
 Operations:
    generateFile: Create file of random Task objects
    checkJobIdRepeating: Make sure that current jobId value isn't already taken
    sortVector: Sort vector (v) of Task objects
    displayVector: Display size and contents of vector<Task>
    operator<<: Put contents of vector<Task> into output stream
 
 Copyright © 2016 Brenna Olson. All rights reserved.
 REUSE AND REDISTRIBUTION NOTICE: You may not modify or redistribute this code in any form including, but not limited to, source or binary. You may download it for informational purposes only.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Task.h"
using namespace std;


const int MAX_ENTRIES = 100;

void generateFile(ofstream &file);
void checkJobIdRepeating(int &job, int endIndex, int a[]);
void sortVector(vector<Task> &v);
void displayVector(vector<Task> v);
void displayVectorContents(vector<Task> v);
ostream &operator<<(ostream &out, const vector<Task> &v);


int main() {

    vector<Task> cpuOnly,
                 cpuAndDisk,
                 cpuAndIO;
    Task input(1);
    
    ofstream outfile;
    ifstream infile;
    outfile.open("TaskList.txt");
    
    if (!outfile) {
        cerr << "Unable to open file - exiting program" << endl;
        exit(1107);
    }
    
    generateFile(outfile);
    
    infile.open("TaskList.txt");
    if (!infile) {
        cerr << "Unable to open file - exiting program" << endl;
        exit(1107);
    }
    
    // add file contents to vectors based on task type
    for (int i = 0; i < MAX_ENTRIES; i++) {
        infile >> input;
        if (input.getType() == 1)
            cpuOnly.push_back(input);
        else if (input.getType() == 2)
            cpuAndDisk.push_back(input);
        else
            cpuAndIO.push_back(input);
    }
    
    sortVector(cpuOnly);
    sortVector(cpuAndDisk);
    sortVector(cpuAndIO);
    
    cout << "CPU Only: " << endl;
    displayVector(cpuOnly);
    cout << "CPU and Disk Space: " << endl;
    displayVector(cpuAndDisk);
    cout << "CPU and I/O Devices: " << endl;
    displayVector(cpuAndIO);
    
    return 0;
}


//******************************************************************************
// Function: generateFile
//
// Purpose: Create file of random Task objects
//
// PreCondition: file must be open
//
// PostCondition: file contains random Task objects
//******************************************************************************

void generateFile(ofstream &file) {
    //srand(time(NULL));
    int type,
        jobId,
        spaceAmount,
        deviceDesignator,
        numbersUsed[MAX_ENTRIES];
    char drive;
    string printerName = "  ";
    
    for(int i = 0; i < 100; i++) {
        // generate task type
        type = 1 + rand() % 3;
        file << type << ' ';
        
        // generate jobId
        jobId = 1000 + rand() % 100;
        
        // 1st value doesn't need to be checked since it's the only value
        if (i > 0)
            checkJobIdRepeating(jobId, i, numbersUsed);
        
        numbersUsed[i] = jobId;
        file << jobId << ' ';
        
        // generate other parts of CPU and disk space
        if (type == 2) {
            spaceAmount = 1 + rand() % 200;
            file << spaceAmount << ' ';
            drive = 'A' + rand() % 3;
            file << drive;
        }
        
        // generate other parts of CPU and I/O
        else if (type == 3) {
            deviceDesignator = 1 + rand() % 3;
            file << deviceDesignator << ' ';
            
            printerName.at(0) = 'A' + rand() % 26;
            printerName.at(1) ='A' + rand() % 26;
            file << printerName;
        }
        
        file << endl;
    } // end for
}


//******************************************************************************
// Function: checkJobIdRepeating
//
// Purpose: Make sure that current job value isn't already taken
//
// PreCondition: a contains more than 1 value
//
// PostCondition: job's value is changed if it's already taken
//******************************************************************************

void checkJobIdRepeating(int &job, int endIndex, int a[]) {
    
    bool numberRepeated;
    
    
    do {
        numberRepeated = false;
        
        for (int i = 0; i < endIndex && numberRepeated == false; i++) {
            if (job == a[i])
                numberRepeated = true;
        }
        
        if (numberRepeated)
            job = 1000 + rand() % 100;
        
    } while (numberRepeated);
}


//******************************************************************************
// Function: sortVector
//
// Purpose: Sort vector (v) of Task objects
//
// PreCondition: Vector must be nonempty
//
// PostCondition: v's contents are sorted by jobId
//******************************************************************************

void sortVector(vector<Task> &v) {
    sort(v.begin(), v.end());
}


//******************************************************************************
// Function: displayVector
//
// Purpose: Display size of vector<Task>
//
// PreCondition: None
//
// PostCondition: Size of vector<Task> displayed on screen
//******************************************************************************

void displayVector(vector<Task> v) {
    cout << "Size: " << v.size() << endl;
    
    cout << "Job Id";
    if (v[0].getType() == 2)
        cout << "  Disk Space  Drive Designator";

    else if (v[0].getType() == 3)
        cout << "  Device Designator  Printer Name";
    
    cout << endl;
    cout << v << endl;
}


//******************************************************************************
// Function: operator<<
//
// Purpose: Put contents of vector<Task> into output stream
//
// PreCondition: None
//
// PostCondition: Contents of vector<Task> in output stream
//******************************************************************************

ostream &operator<<(ostream &out, const vector<Task> &v) {
    for (int i = 0; i < v.size(); i++)
        out << v[i] << endl;
    return out;
}
