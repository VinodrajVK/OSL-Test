#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *v[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc < 2)
    {
        printf("Directory name not entered\n");
        exit(0);
    }
    if ((dp = opendir(v[1])) == NULL)
    {
        printf("Directory not found\n");
        exit(0);
    }
    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\t", dirp->d_name);
    }
    closedir(dp);
    return 0;
}