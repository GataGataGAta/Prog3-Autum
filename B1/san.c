#include<stdio.h>
#include<stdlib.h>

#define N 40

int main(void)
{
    char filename[] = "out.txt";

    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    int i, j, k;
    for(i = 0; i < N; i++)
    {
        j = i % 10;
        k = i / 10;
        if(i % 3 == 0 || j == 3 || k == 3)
        {
            if(i != 0)
            {
            fprintf(fp, "%d\n", i);
            }
        }
        //printf("%d\n", k);
    }
    fclose(fp);
    return EXIT_SUCCESS;

}