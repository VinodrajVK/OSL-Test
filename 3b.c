#include <stdio.h>

struct process {
  int id, at, bt, ct, wt, tt, rt, qf;
} p[10];

int n, q[10],front = -1, rear = -1;

void enqueue(int i) {
  p[i].qf = 1;
  q[++rear] = i;
  if (front == -1)
    front = 0;
}

int dequeue() {
  int temp = q[front];
  if (front == rear)
    front = rear = -1;
  else
    front++;
  p[temp].qf = 0;
  return temp;
}

void sortByArrival() {
  struct process temp;
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (p[i].at > p[j].at) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
}

void rrsched(int tq) {
  sortByArrival();
  int i;
  enqueue(0);
  int time = p[0].at;
  printf("Process execution order: ");
  for (int cp = 0; cp < n;) {
    i = dequeue();
    if (p[i].rt <= tq) {
      time += p[i].rt;
      p[i].rt = 0;
      cp++;
      printf(" %d ", p[i].id);
      p[i].ct = time;
      p[i].tt = time - p[i].at;
      p[i].wt = p[i].tt - p[i].bt;
      for (int j = 0; j < n; j++)
        if (p[j].at <= time && p[j].rt > 0 && p[j].qf != 1)
          enqueue(j);
    } else {
      time += tq;
      p[i].rt -= tq;
      printf(" %d ", p[i].id);
      for (int j = 0; j < n; j++)
        if (p[j].at <= time && p[j].rt > 0 && i != j && p[j].qf != 1)
          enqueue(j);
      enqueue(i);
    }
  }
}

void main() 
{
  int i, j, time = 0, tq;
  float avgwt = 0;
  printf("Enter no of processes:");
  scanf("%d", &n);
  for (i = 0; i < n; i++) 
  {
    p[i].id = i + 1;
    printf("\nEnter the arrival time and burst time of process %d: ", p[i].id);
    scanf("%d%d", &p[i].at, &p[i].bt);
    p[i].rt = p[i].bt;
    p[i].qf = 0;
  }
  printf("\nEnter the time quantum:");
  scanf("%d", &tq);
  rrsched(tq);
  printf("\nID\tAT\tBT\tCT\tTT\tWT\n");
  for (i = 0; i < n; i++) 
  {
    avgwt += p[i].wt;
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct,p[i].tt, p[i].wt);
  }
  printf("\nAverage waiting time:%f\n", avgwt / n);
}
