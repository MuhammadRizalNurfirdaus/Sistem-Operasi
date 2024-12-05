#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int priority;
};

void priorityScheduling(struct Process proc[], int n) {
    // Short proses dari priorty
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    printf("Process ID\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].priority);
    }
}

int main() {
    struct Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
    int n = sizeof(proc) / sizeof(proc[0]);

    printf("Penjadwalan Prioritas (Non-Preemptive):\n");
    priorityScheduling(proc, n);

    return 0;
}