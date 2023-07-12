#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
int i;
pid_t pid;
const int SIZE=4096;
void *ptr;
int shmid;
if(argc<2)
{
printf("Error : Not passing arguments in Command Line\n");
exit(0);
}
else
{
pid = fork();
if(pid==0)
{
execlp("./prime","prime",argv[1],argv[2],NULL);
}
else if(pid >0)
{
wait(NULL);
printf("\nPARENT : Child Completed\n");
shmid = shm_open("VK",O_RDONLY,0666);
ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shmid,0);
printf("Parent printing\n");
printf("%s",(char *)ptr);
printf("\n");
shm_unlink("VK");
}
return 0;
}
}
