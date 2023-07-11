#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *v[])
{
    char str[100];
    if (argc < 3)
    {
        printf("File name not entered\n");
        exit(0);
    }
    if (argc < 2)
    {
        printf("File name or pattern not entered\n");
        exit(0);
    }
    FILE *fp = fopen(v[2], "r");
    while (!feof(fp))
    {
        fgets(str, 100, fp);
        if (strstr(str, v[1]))
        {
            printf("%s", str);
            break;
        }
    }
    fclose(fp);
    return 0;
}