#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main(int argc, char *v[])
{
    if (argc < 2)
    {
        printf("File name not entered\n");
        exit(0);
    }
    char buf[10];
    int fd = open(v[1], 0666);
    if (fd == -1)
    {
        printf("File not found\n");
        exit(0);
    }
    printf("Reading first 10 Characters\n");
    int n = read(fd, buf, 10);
    write(1, buf, n);
    printf("\nSkipping 5 Characters from current position\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buf, 10);
    write(1, buf, n);
    printf("\nGoing to 5th Character from last\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buf, 5);
    write(1, buf, n);
    printf("\nGoing to 3rd Character from start\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buf, 10);
    write(1, buf, n);
}