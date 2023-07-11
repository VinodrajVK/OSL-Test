#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *v[])
{
    if (argc < 2)
    {
        printf("File name not entered\n");
        exit(0);
    }
    char str[100];
    FILE *fp = fopen(v[1], "r");
    if (fp == NULL)
    {
        printf("File does not exist\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fgets(str, 100, fp);
        printf("%s", str);
    }
}