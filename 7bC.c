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
int k=2,n1,n2,n3;
void *ptr;
int shmid = shmget((key_t)121212,4096,0666|IPC_CREAT);
ptr = shmat(shmid,NULL,0666);
printf("CHILD\n");
int i = atoi(argv[1]);
n1=0;
n2=1;
sprintf(ptr,"%d ",n1);
ptr+=strlen(ptr);
printf("%d ",n1);
sprintf(ptr,"%d ",n2);
ptr+=strlen(ptr);
printf("%d ",n2);
while(k!=i)
{
n3=n1+n2;
sprintf(ptr,"%d ",n3);
printf("%d ",n3);
n1=n2;
n2=n3;
ptr+=strlen(ptr);
k++;
}
return 0;
}
