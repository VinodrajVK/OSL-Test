#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
int k=1,odd=1,n;
void *ptr;
int shmid = shmget((key_t)151515,4096,IPC_CREAT|0666);
ptr = shmat(shmid,NULL,0666);
printf("CHILD\n");
sscanf(argv[1],"%d",&n);
n = atoi(argv[1]);
while(k<=n)
{
sprintf(ptr,"%d ",odd);
printf("%d ",odd);
ptr+=strlen(ptr);
k++;
odd+=2;
}
return 0;
}
