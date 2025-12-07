#include <stdio.h>
#include "scheduler.h"

int main() {
    Process p[20];
    int n;
    int totalTime = 0;   // total completion time of schedule
    int busyTime = 0;    // time CPU was actually executing processes

    printf("Adaptive Real-Time Scheduler — Day 5\n");
    printf("------------------------------------\n");

    // DAY 3: Input + Sorting + Display
    takeProcessInput(p, &n);
    sortByArrival(p, n);
    displayProcesses(p, n);

    // DAY 4 + 5: Run scheduler (now returns timing info)
    runScheduler(p, n, &totalTime, &busyTime);

    // DAY 5: Calculate WT, TAT, RT, etc.
    calculateMetrics(p, n, totalTime, busyTime);

    // DAY 5: Print final results table + averages + CPU utilization
    printResults(p, n, totalTime, busyTime);

    return 0;
}
