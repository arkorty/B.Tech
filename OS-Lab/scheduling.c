#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Structure for a process
struct Process {
    int pid;      // Process ID
    int bt;       // Burst time
    int at;       // Arrival time
    int priority; // Priority (lower value means higher priority)
};

// Function to perform FCFS scheduling
void FCFS(struct Process proc[], int n) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = proc[i - 1].bt + wt[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nFCFS Scheduling:\n");
    printf("PID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

// Function to perform Non-preemptive SJF scheduling
void SJF_NonPreemptive(struct Process proc[], int n) {
    int wt[n], tat[n], completed = 0;
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int currentTime = 0, total_wt = 0, total_tat = 0;

    while (completed < n) {
        int min_bt = INT_MAX, index = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && proc[i].at <= currentTime &&
                proc[i].bt < min_bt) {
                min_bt = proc[i].bt;
                index = i;
            }
        }

        if (index != -1) {
            visited[index] = true;
            wt[index] = currentTime - proc[index].at;
            currentTime += proc[index].bt;
            tat[index] = wt[index] + proc[index].bt;
            total_wt += wt[index];
            total_tat += tat[index];
            completed++;
        } else {
            currentTime++;
        }
    }

    printf("\nNon-Preemptive SJF Scheduling:\n");
    printf("PID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

// Function to perform Round Robin scheduling
void RoundRobin(struct Process proc[], int n, int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = proc[i].bt;
    int wt[n], tat[n], t = 0;
    for (int i = 0; i < n; i++)
        wt[i] = 0;

    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - proc[i].bt;
                    rem_bt[i] = 0;
                }
            }
        }
    } while (!done);

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = proc[i].bt + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("PID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &proc[i].at);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &proc[i].priority);
    }

    FCFS(proc, n);
    SJF_NonPreemptive(proc, n);
    RoundRobin(proc, n, 2); // Quantum time set to 2

    return 0;
}
