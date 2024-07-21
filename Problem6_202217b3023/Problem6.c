#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of processes
#define MAX_PROCESSES 10

// Structure to hold process information
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate average waiting time and average turnaround time
void calculateAverages(struct Process processes[], int n, float *avg_wt, float *avg_tat) {
    int i;
    float total_wt = 0, total_tat = 0;

    // Calculate turnaround time and waiting time for each process
    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_wt += processes[i].waiting_time;
        total_tat += processes[i].turnaround_time;
    }

    // Calculate averages
    *avg_wt = total_wt / n;
    *avg_tat = total_tat / n;
}

// Function to perform scheduling using FCFS algorithm
void scheduleFCFS(struct Process processes[], int n) {
    int i;
    int current_time = 0;

    // Calculate waiting times
    for (i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, i;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time for process P%d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i;
    }

    printf("Enter arrival times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival time for process P%d: ", i);
        scanf("%d", &processes[i].arrival_time);
    }

    // Perform scheduling using FCFS
    scheduleFCFS(processes, n);

    // Calculate average waiting time and average turnaround time
    calculateAverages(processes, n, &avg_waiting_time, &avg_turnaround_time);

    // Display results
    printf("\nProcess\t\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
