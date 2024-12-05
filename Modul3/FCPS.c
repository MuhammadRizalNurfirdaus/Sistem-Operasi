#include <stdio.h>
#include <conio.h>

int main(){
    int bt[20], wt[20], tat[20], i, n;  
    float wtavg, tatavg;

    // Input jumlah proses
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);

    // Input Burst Time untuk setiap proses
    for (int i=0; i<n; i++){
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }

    // Hitung waktu tunggu dan turnaround
    wt[0] = 0;
    wtavg = 0;
    tat[0] = bt[0];
    tatavg = tat[0];

    // Hitung waktu tunggu dan turnaround untuk setiap proses
    for(i=1; i<n; i++){
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg += wtavg + wt[i];
        tatavg += tatavg + tat[i];
    }

    // Tampilakn hasil
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i = 0; i<n; i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    }

    // Hitung dan tampilkan rata-rata waktu tunggu dan turnaround
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);

    getch();
    return 0;
}