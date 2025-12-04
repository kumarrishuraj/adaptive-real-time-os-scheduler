#ifndef SCHEDULER_H
#define SCHEDULER_H

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

void takeProcessInput(Process p[], int *n);
void sortByArrival(Process p[], int n);
void displayProcesses(Process p[], int n);
#endif