#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *Sum(void *arg);
void *Fact(void *arg);
int sum=0,fact=1;
void main(int argc, char *argv[])
{
pthread_t T1,T2;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&T1,&attr,*Sum,argv[1]);
pthread_create(&T2,&attr,*Fact,argv[1]);
pthread_join(T1,NULL);
pthread_join(T2,NULL);
printf("Inside Main Thread\n");
printf("Sum = %d\n",sum);
printf("Factorial = %d\n",fact);
}

void *Sum(void *param)
{
int i,n;
n=atoi(param);
printf("Inside Sum Thread\n");
for(i=1;i<=n;i++)
sum+=i;
printf("Sum Thread Completed\n");
}

void *Fact(void *param)
{
int i,n;
n=atoi(param);
printf("Inside Factorial Thread\n");
for(i=2;i<=n;i++)
fact*=i;
printf("Factorial Thread Completed\n");
}
