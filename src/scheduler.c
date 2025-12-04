#include <stdio.h>
#include "scheduler.h"
// 1️⃣ TAKE PROCESS INPUT
// ------------------------------
void takeProcessInput(Process p[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\n--- Enter details for Process %d ---\n", i + 1);
        printf("PID: ");
        scanf("%s", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
        printf("Deadline: ");
        scanf("%d", &p[i].deadline);
        printf("Priority: ");
        scanf("%d", &p[i].priority);

        p[i].remaining = p[i].burst;
        p[i].start = -1;
        p[i].finish = 0;
        p[i].waiting = 0;
        p[i].turnaround = 0;
    }
}

// ------------------------------
// 2️⃣ SORT BY ARRIVAL TIME
// ------------------------------
void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// ------------------------------
// 3️⃣ DISPLAY PROCESS TABLE
// ------------------------------
void displayProcesses(Process p[], int n) {
    printf("\nPID\tAT\tBT\tDL\tPR\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].deadline,
               p[i].priority);
    }

    printf("--------------------------------------\n");
}
void runScheduler(Process p[], int n) {
    printf("Scheduler logic will be implemented in upcoming days.\n");
}
