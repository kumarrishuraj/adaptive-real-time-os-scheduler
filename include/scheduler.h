#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int deadline;
    int priority;
    int remaining;
    int waiting;
    int turnaround;
} Process;

void runScheduler(Process p[], int n);

#endif
