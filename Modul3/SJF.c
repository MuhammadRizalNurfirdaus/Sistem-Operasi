#include<stdio.h>
#include<conio.h>
int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp; // Deklarasi array dan variabel
    float wtavg, tatavg; // variabel untuk rata-rata waiting time dan turnaround time

    // Minta user untuk memasukkan jumlah proses
    printf("\nEnter the number of processes .. ");
    scanf("%d", &n);

    // Loop untuk memasukkan burst time untuk setiap proses
    for(i=0;i<n; i++)
    {
        p[i] = i; // Inisialisasi array p dengan nomor proses (P0, P1, P2, dst.)
        printf("Enter Burst Time for Process %d.. ", i);
        scanf("%d", &bt[i]); // Input burst time untuk proses ke-i
    }

    // Sorting burst time dengan metode bubble sort (ascending) agar sesuai dengan algoritme SJF
    // Sorting ini juga menukar nomor proses agar sesuai dengan burst time
    for(i = 0; i < n; i++)
    {
        for(k = i+1; k < n; k++)
        {
            if(bt[i] > bt[k]) // Jika burst time ke-i lebih besar dari burst time ke-k
            {
                // Tukar burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Tukar juga nomor proses agar tetap sesuai
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Inisialisasi waktu tunggu (wt) dan turnaround time (tat) untuk proses pertama
    wt[0] = wtavg = 0;
    // Proses pertama tidak memiliki waktu tunggu
    tat[0] = tatavg = bt[0]; // Turnaround time untuk proses pertama sama dengan burst time-nya

    // Loop untuk menghitung waktu tunggu dan turnaround time untuk proses lainnya
    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1]; // Waktu tunggu dihitung berdasarkan waktu tunggu dan burst time proses sebelumnya
        tat[i] = wt[i] + bt[i]; // Turnaround time = waiting time + burst time
        wtavg = wtavg + wt[i]; // Total waktu tunggu untuk rata-rata
        tatavg = tatavg + tat[i]; // Total turnaround time untuk rata-rata
    }

    // Output tabel hasil: menampilkan proses, burst time, waiting time, dan turnaround time
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIMME\n");
    for(i = 0; i< n; i++)
    printf("\n\t P&d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

// Output rata-rata waktu tunggu dan turnaround time
printf("\nAverage Waiting Time --%f", wtavg/n);
printf("\nAverage Turnaround Time --%f", tatavg/n);
getch();
}