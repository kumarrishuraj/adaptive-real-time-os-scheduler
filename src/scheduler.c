#include <stdio.h>
#include "scheduler.h"

//
// ------------------------------
// 1️⃣ TAKE PROCESS INPUT (Now with Validation - DAY 7)
// ------------------------------
void takeProcessInput(Process p[], int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("\n--- Enter details for Process %d ---\n", i + 1);

        printf("PID: ");
        scanf("%s", p[i].pid);

        // Arrival Time
        do {
            printf("Arrival Time (>= 0): ");
            scanf("%d", &p[i].arrival);
            if (p[i].arrival < 0)
                printf("Invalid input! Arrival Time cannot be negative.\n");
        } while (p[i].arrival < 0);

        // Burst Time
        do {
            printf("Burst Time (> 0): ");
            scanf("%d", &p[i].burst);
            if (p[i].burst <= 0)
                printf("Invalid input! Burst Time must be positive.\n");
        } while (p[i].burst <= 0);

        // Deadline
        do {
            printf("Deadline (>= Arrival Time): ");
            scanf("%d", &p[i].deadline);
            if (p[i].deadline < p[i].arrival)
                printf("Invalid! Deadline must be >= arrival time.\n");
        } while (p[i].deadline < p[i].arrival);

        // Priority
        do {
            printf("Priority (>= 1): ");
            scanf("%d", &p[i].priority);
            if (p[i].priority < 1)
                printf("Invalid input! Priority must be >= 1.\n");
        } while (p[i].priority < 1);

        // Initialize runtime fields
        p[i].remaining = p[i].burst;
        p[i].start = -1;
        p[i].finish = 0;
        p[i].waiting = 0;
        p[i].turnaround = 0;
    }
}

//
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

//
// ------------------------------
// 3️⃣ DISPLAY PROCESS TABLE
// ------------------------------
void displayProcesses(Process p[], int n) {
    printf("\nPID\tAT\tBT\tDL\tPR\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].deadline, p[i].priority);
    }

    printf("--------------------------------------\n");
}

//
// ------------------------------
// 4️⃣ SELECT BEST PROCESS (Adaptive Priority)
// ------------------------------
int selectProcess(Process p[], int n, int currentTime) {
    int selected = -1;
    int bestPriority = -999999;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival <= currentTime && p[i].remaining > 0) {

            int effectivePriority = p[i].priority - (p[i].deadline - currentTime);

            if (effectivePriority > bestPriority) {
                bestPriority = effectivePriority;
                selected = i;
            }
        }
    }

    return selected;
}

//
// ------------------------------
// 5️⃣ RUN SCHEDULER
// ------------------------------
void runScheduler(Process p[], int n, int *totalTime, int *busyTime) {
    int completed = 0;
    int currentTime = 0;
    *busyTime = 0;

    printf("\nGantt Chart:\n");

    while (completed < n) {
        int idx = selectProcess(p, n, currentTime);

        if (idx == -1) {  
            printf(" | IDLE ");
            currentTime++;
            continue;
        }

        if (p[idx].start == -1)
            p[idx].start = currentTime;

        printf(" | %s ", p[idx].pid);

        p[idx].remaining--;
        currentTime++;
        (*busyTime)++;

        if (p[idx].remaining == 0) {
            p[idx].finish = currentTime;
            completed++;
        }
    }

    printf(" |\n");

    *totalTime = currentTime;
}

//
// ------------------------------
// 6️⃣ CALCULATE METRICS (WT, TAT, RT)
// ------------------------------
void calculateMetrics(Process p[], int n, int totalTime, int busyTime) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].finish - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
    }
}

//
// ------------------------------
// 7️⃣ PRINT FINAL RESULTS TABLE
// ------------------------------
void printResults(Process p[], int n, int totalTime, int busyTime) {
    float sumWT = 0, sumTAT = 0, sumRT = 0;

    printf("\nFinal Results:\n");
    printf("PID\tAT\tBT\tCT\tRT\tWT\tTAT\tDeadlineMiss\n");

    for (int i = 0; i < n; i++) {

        int RT = p[i].start - p[i].arrival;
        int deadlineMiss = (p[i].finish > p[i].deadline);

        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
               p[i].pid, p[i].arrival, p[i].burst,
               p[i].finish, RT, p[i].waiting,
               p[i].turnaround,
               deadlineMiss ? "YES" : "NO");

        sumWT += p[i].waiting;
        sumTAT += p[i].turnaround;
        sumRT += RT;
    }

    printf("\nAverage Waiting Time     : %.2f", sumWT / n);
    printf("\nAverage Turnaround Time  : %.2f", sumTAT / n);
    printf("\nAverage Response Time    : %.2f", sumRT / n);

    float cpuUtil = (busyTime / (float)totalTime) * 100.0f;
    printf("\nCPU Utilization          : %.2f%%\n", cpuUtil);
}

//
// ------------------------------
// 8️⃣ SAVE REPORT TO FILE (DAY 6)
// ------------------------------
void saveReport(Process p[], int n, int totalTime, int busyTime) {
    FILE *f = fopen("report.txt", "w");

    fprintf(f, "Adaptive Real-Time Scheduler Report\n");
    fprintf(f, "------------------------------------\n\n");

    fprintf(f, "Final Results:\n");
    fprintf(f, "PID\tAT\tBT\tCT\tRT\tWT\tTAT\tDeadlineMiss\n");

    float sumWT = 0, sumTAT = 0, sumRT = 0;

    for (int i = 0; i < n; i++) {

        int RT = p[i].start - p[i].arrival;
        int deadlineMiss = (p[i].finish > p[i].deadline);

        fprintf(f, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\n",
                p[i].pid, p[i].arrival, p[i].burst,
                p[i].finish, RT, p[i].waiting,
                p[i].turnaround,
                deadlineMiss ? "YES" : "NO");

        sumWT += p[i].waiting;
        sumTAT += p[i].turnaround;
        sumRT += RT;
    }

    fprintf(f, "\nAverage Waiting Time     : %.2f", sumWT / n);
    fprintf(f, "\nAverage Turnaround Time  : %.2f", sumTAT / n);
    fprintf(f, "\nAverage Response Time    : %.2f", sumRT / n);

    float cpuUtil = (busyTime / (float)totalTime) * 100.0f;
    fprintf(f, "\nCPU Utilization          : %.2f%%\n", cpuUtil);

    fclose(f);
}
