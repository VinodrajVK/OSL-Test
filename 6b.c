#include <stdio.h>
typedef struct
{
    int id, at, bt, ct, tat, wt, rt;
} Process;
void sort(Process proc[], int n)
{
    Process t;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (proc[j].bt > proc[j + 1].bt)
            {
                t = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = t;
            }
}
void sjfscheduling(Process proc[], int n)
{
    int i, f = 0, time = 0, exec, num = n;
    sort(proc, n);
    while (num > 0)
    {
        f = 0;
        exec = n - 1;
        for (i = 0; i < n; i++)
        {
            if (proc[i].rt > 0 && proc[i].at <= time)
            {
                exec = i;
                f = 1;
                break;
            }
        }
        if (f == 0)
            time++;
        else
        {
            time += proc[exec].bt;
            proc[exec].ct = time;
            printf("Process-%d completed at %d\n", proc[exec].id, proc[exec].ct);
            proc[exec].tat = proc[exec].ct - proc[exec].at;
            proc[exec].wt = proc[exec].tat - proc[exec].bt;
            proc[exec].rt = 0;
            num--;
        }
    }
}
void printdata(Process processes[], int n)
{
    int wtsum = 0, tatsum = 0;
    printf("P-ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        wtsum += processes[i].wt;
        tatsum += processes[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
    }
    printf("Average Waiting Time : %.2f\n", (float)wtsum / n);
    printf("Average Turnaround Time : %.2f\n", (float)tatsum / n);
}
int main()
{
    int n;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    Process processes[n];
    for (int i = 0; i < n; i++)
    {
        printf("Process-%d\n", i + 1);
        processes[i].id = i + 1;
        printf("Enter the Arrival Time : ");
        scanf("%d", &processes[i].at);
        printf("Enter the Burst Time : ");
        scanf("%d", &processes[i].bt);
        processes[i].rt = processes[i].bt;
    }
    sjfscheduling(processes, n);
    printdata(processes, n);
    return 0;
}