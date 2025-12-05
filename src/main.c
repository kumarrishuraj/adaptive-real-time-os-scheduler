#include <stdio.h>
#include "scheduler.h"

int main() {
    Process p[20];
    int n;

    printf("Adaptive Real-Time Scheduler — Day 4\n");
    printf("------------------------------------\n");

    // DAY 3: Input + Sorting + Display
    takeProcessInput(p, &n);
    sortByArrival(p, n);
    displayProcesses(p, n);

    // DAY 4: Run the adaptive scheduler
    runScheduler(p, n);

    return 0;
}
