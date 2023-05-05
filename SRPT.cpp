class Process:
  #include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;    
    int at;     
    int bt;     
    int ct;     
    int tat;    
    int wt;     
    int rt;
};

int n = 4;

void srpt(struct process *p) {
    int t = 0;  
    int complete = 0;   
    int shortest = 0;   
    int finish_time;    
    while (complete != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && p[i].rt > 0) {
                if (shortest == -1 || p[i].rt < p[shortest].rt) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }
        p[shortest].rt--;
        t++;
        if (p[shortest].rt == 0) {
            complete++;
            finish_time = t;
            p[shortest].ct = finish_time;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
    }
}

void print_processes(struct process *p) {
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    struct process p[] = {{1, 0, 5}, {2, 1, 3}, {3, 2, 3}, {4, 4, 1}};
    for (int i = 0; i < n; i++) {
        p[i].rt = p[i].bt;
    }
    srpt(p);
    print_processes(p);
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("Average Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f");
  def_init_(self, pid, arrival_time, burst_time):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.start_time = None
        self.finish_time = None
        self.waiting_time = 0
        self.turnaround_time = 0
    
    def execute(self, current_time):
        self.start_time = current_time
        self.remaining_time -= 1
        if self.remaining_time == 0:
            self.finish_time = current_time + 1
    
    def __str__(self):
        return f"P{self.pid}"
    

def SRPT(processes):
    n = len(processes)
    current_time = 0
    completed_processes = []
    ready_queue = []
    
    while len(completed_processes) < n:
        for p in processes:
            if p.arrival_time == current_time:
                ready_queue.append(p)
        ready_queue = sorted(ready_queue, key=lambda p: p.remaining_time)
        
        if ready_queue:
            current_process = ready_queue.pop(0)
            current_process.execute(current_time)
            if current_process.remaining_time == 0:
                completed_processes.append(current_process)
                current_process.turnaround_time = current_process.finish_time - current_process.arrival_time
                current_process.waiting_time = current_process.turnaround_time - current_process.burst_time
        else:
            current_time += 1
        current_time += 1
    avg_waiting_time = sum([p.waiting_time for p in completed_processes]) / n
    avg_turnaround_time = sum([p.turnaround_time for p in completed_processes]) / n
    
    return (avg_waiting_time, avg_turnaround_time)
processes = [Process(1, 0, 5), Process(2, 1, 3), Process(3, 2, 3), Process(4, 4, 1)]
avg_waiting_time, avg_turnaround_time = SRPT(processes)
print(f"Average Waiting Time: {avg_waiting_time:.2f} ms")
print(f"Average Turnaround Time: {avg_turnaround_time:.2f} ms")

