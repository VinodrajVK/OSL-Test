#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
    pid_t ppid, mypid, child_pid;
    child_pid = fork();
    if (child_pid < 0)
    {
        printf("Fork Failed\n");
        exit(0);
    }
    if (child_pid == 0)
    {
        mypid = getpid();
        ppid = getppid();
        printf("[CHILD] Child Executing\n");
        printf("[CHILD] My PID = %d\n", mypid);
        printf("[CHILD] My Parent PID = %d\n", ppid);
        printf("[CHILD] Child Sleeping for 10 seconds\n");
        sleep(10);
        printf("[CHILD] Child is now an Orphan Process adopted by Init Process\n");
    }
    else
    {
        mypid = getpid();
        ppid = getppid();
        printf("[PARENT] Parent Executing\n");
        printf("[PARENT] My PID = %d\n", mypid);
        printf("[PARENT] My Parent PID = %d\n", ppid);
        printf("[PARENT] Parent Exiting\n");
        exit(0);
    }
}