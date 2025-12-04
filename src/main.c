#include <stdio.h>
#include "scheduler.h"

int main() {
    Process p[20];
    int n;

    printf("Adaptive Real-Time Scheduler — Day 3\n");
    printf("------------------------------------\n");

    takeProcessInput(p, &n);
    sortByArrival(p, n);
    displayProcesses(p, n);

    return 0;
}
