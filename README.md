# Adaptive Real-Time OS Scheduler

## 📌 Project Overview
This project implements an Adaptive OS Scheduler for real-time systems. The scheduler dynamically adjusts process priorities based on deadlines, workload, and current time. This creates a real-time, deadline-aware adaptive scheduling mechanism.

The adaptive priority formula used:
effectivePriority = priority - (deadline - currentTime)

This ensures processes closer to deadlines automatically gain higher priority.

---

## 🎯 Features

✔ Adaptive real-time scheduling  
✔ Dynamic priority calculation  
✔ Deadline awareness  
✔ Preemptive behavior (decisions every time unit)  
✔ Gantt chart display  
✔ Process metrics (CT, RT, WT, TAT)  
✔ Deadline miss detection  
✔ CPU utilization calculation  
✔ Input validation (arrival ≥0, burst >0, deadline ≥ arrival, priority ≥1)  
✔ Multi-run support  
✔ Auto-generated report.txt  

---

## 📂 Project Structure

Project/
│── include/
│   └── scheduler.h
│
│── src/
│   ├── main.c
│   └── scheduler.c
│
│── bin/
│   └── scheduler.exe
│
│── report.txt
│── README.md

---

## 🛠️ Compilation
Run this command:

gcc src/main.c src/scheduler.c -Iinclude -o bin/scheduler.exe

---

## ▶️ Running the Program
bin/scheduler.exe

Program steps:
1. Enter number of processes  
2. Enter PID, Arrival, Burst, Deadline, Priority  
3. Scheduler executes using adaptive priority  
4. Gantt chart printed  
5. Full metrics displayed  
6. Report saved  
7. Choose to run again (y/n)  

---

## 🧪 Sample Input
3
P1 0 4 10 2
P2 1 3 6 1
P3 2 5 9 3

---

## 📘 Sample Output
PID   AT  BT  CT  RT  WT  TAT  DeadlineMiss
P1    0   4   6   0   2   6    NO
P2    1   3   10  2   6   9    YES
P3    2   5   15  7   8   13   YES

CPU Utilization: 86.27%

---

## 📄 Report File (report.txt)
Contains:
- Final result table  
- WT, TAT, RT  
- Average metrics  
- CPU Utilization  
- Deadline Miss summary  

---

## 🔍 Adaptive Scheduling Explained
Formula used:
effectivePriority = priority - (deadline - currentTime)

As currentTime approaches deadline:
- effectivePriority increases  
- urgent processes get higher priority  
- system behaves like a real-time scheduler (similar to EDF + dynamic priority)  

---

## 👨‍💻 Developed by:-
Name: Rishuraj Kumar | 
Course: B.Tech CSE (AI/ML)  
Subject: Operating Systems (CSE316)  
Project Title: Adaptive OS Scheduler for Real-Time Systems  

---

## ✅ Project Status
Project successfully completed across 8 structured days with:
- Modular design  
- Real-time adaptive scheduling  
- Metrics + Gantt chart  
- Input validation  
- Multi-run support  
- Report generation  
- Git branching workflow  

✔ Final Submission Ready