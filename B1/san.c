#include<stdio.h>
#include<stdlib.h>

#define N 40

int main(void)
{
    int i, j, k;
    j = 0;
    k = 0;
    for(i = 0; i < N; i++)
    {
        j = i % 10;
        k = i / 10;
        if(i % 3 == 0 || j == 3 || k == 3)
        {
            if(i != 0)
            {
            printf("%d\n", i);
            }
        }
    }
    return 0;

}