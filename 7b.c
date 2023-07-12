#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
int i,k,n1,n2,n3;
pid_t pid;
const int SIZE=4096;
void *ptr;
int shmid;
if(argc>1)
{
sscanf(argv[1],"%d",&i);
if(i<1)
{
printf("Error Input : %d\n",i);
return 0;
}
}
else
{
printf("Error : Not passing N in Command Line\n");
exit(0);
}
pid = fork();
if(pid==0)
{
execlp("./fib","fib",argv[1],NULL);
}
else if(pid >0)
{
wait(NULL);
printf("\nPARENT : Child Completed\n");
shmid = shmget((key_t)121212,4096,0666);
ptr = shmat(shmid,NULL,0666);
printf("Parent printing\n");
printf("%s",(char *)ptr);
printf("\n");
shmdt(ptr);
}
return 0;
}


