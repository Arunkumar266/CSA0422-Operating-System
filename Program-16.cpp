#include <stdio.h>

int main()
{
    int num_processes = 3;
    int burst_time[] = {10, 15, 25};
    int arrival_time[] = {0, 0, 0};  // Assume all processes arrive at time 0

    int completion_time[num_processes];
    int waiting_time[num_processes];
    int turnaround_time[num_processes];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // Calculate completion time for each process
    completion_time[0] = burst_time[0];
    for(int i = 1; i < num_processes; i++)
        completion_time[i] = completion_time[i-1] + burst_time[i];

    // Calculate waiting time and turnaround time for each process
    for(int i = 0; i < num_processes; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting time and average turnaround time
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < num_processes; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
