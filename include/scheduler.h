#ifndef SCHEDULER_H
#define SCHEDULER_H

// ------------------------------
// Process Control Block (PCB)
// ------------------------------
typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int deadline;
    int priority;

    int remaining;
    int start;
    int finish;
    int waiting;
    int turnaround;

} Process;


// ------------------------------
// Day 3 — Input, Sorting, Display
// ------------------------------
void takeProcessInput(Process p[], int *n);     // now includes validation
void sortByArrival(Process p[], int n);
void displayProcesses(Process p[], int n);


// ------------------------------
// Day 4 — Adaptive Scheduling
// ------------------------------
int selectProcess(Process p[], int n, int currentTime);
void runScheduler(Process p[], int n, int *totalTime, int *busyTime);


// ------------------------------
// Day 5 — Metrics Calculation
// ------------------------------
void calculateMetrics(Process p[], int n, int totalTime, int busyTime);
void printResults(Process p[], int n, int totalTime, int busyTime);


// ------------------------------
// Day 6 — Report Output
// ------------------------------
void saveReport(Process p[], int n, int totalTime, int busyTime);

#endif