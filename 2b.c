#include <stdio.h>
typedef struct
{
    int id, at, bt, ct, tat, wt, rt, pri;
} Process;
typedef struct
{
    int id, time;
} Gantt;
Gantt g[10];
int gn = 0;
void printgantt()
{
    int i;
    printf("Gantt Chart\n");
    printf("_________________________________________________________________________________________\n");
    for (i = 0; i <= gn; i++)
        printf("\tP%d\t|", g[i].id);
    printf("\n________________________________________________________________________________________\n");
    for (i = 0; i <= gn; i++)
        printf("\t\t%d", g[i].time);
}
void prioritypscheduling(Process proc[], int n)
{
    int i, f = 0, time = 0, exec = 0, num = n, highp = 99999, pexec = 0;
    while (num > 0)
    {
        for (i = 0; i < n; i++)
        {
            if (proc[i].at <= time && proc[i].pri < highp && proc[i].rt > 0)
            {
                highp = proc[i].pri;
                exec = i;
                f = 1;
            }
        }
        if (f == 0)
            time++;
        else
        {
            if (pexec != exec)
            {
                g[gn].id = proc[pexec].id;
                g[gn++].time = time;
            }
            proc[exec].rt--;
            pexec = exec;
            highp = proc[exec].pri;
            if (proc[exec].rt == 0)
                highp = 99999;
            if (proc[exec].rt == 0)
            {
                proc[exec].ct = time + 1;
                proc[exec].tat = proc[exec].ct - proc[exec].at;
                proc[exec].wt = proc[exec].tat - proc[exec].bt;
                proc[exec].rt = 0;
                num--;
            }
            time++;
        }
    }
    g[gn].id = proc[pexec].id;
    g[gn].time = time;
}
void printdata(Process processes[], int n)
{
    int wtsum = 0, tatsum = 0;
    printf("P-ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        wtsum += processes[i].wt;
        tatsum += processes[i].tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt);
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
    printf("Enter Arrival Time, Burst Time and Priority\n");
    printf("P-ID\tAT\tBT\tPri\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t", i + 1);
        processes[i].id = i + 1;
        scanf("%d%d%d", &processes[i].at, &processes[i].bt, &processes[i].pri);
        processes[i].rt = processes[i].bt;
    }
    prioritypscheduling(processes, n);
    printdata(processes, n);
    printgantt();

    return 0;
}