#include <stdio.h>
#include "scheduler.h"

int main() {
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        
        Process p[20];
        int n;
        int totalTime = 0;     // total completion time of schedule
        int busyTime = 0;      // CPU active time

        printf("\nAdaptive Real-Time Scheduler — Day 7\n");
        printf("------------------------------------\n");

        // DAY 3: Input + Sorting + Display
        takeProcessInput(p, &n);
        sortByArrival(p, n);
        displayProcesses(p, n);

        // DAY 4 + 5: Run scheduler and capture timing info
        runScheduler(p, n, &totalTime, &busyTime);

        // DAY 5: Calculate WT, TAT, RT
        calculateMetrics(p, n, totalTime, busyTime);

        // DAY 5: Print results on console
        printResults(p, n, totalTime, busyTime);

        // DAY 6: Save everything into a report file
        saveReport(p, n, totalTime, busyTime);

        printf("\nReport saved to report.txt\n");

        // DAY 7: Multi-run feature
        printf("\nRun another test? (y/n): ");
        scanf(" %c", &again);
    }

    printf("\nExiting scheduler. Thank you!\n");
    return 0;
}