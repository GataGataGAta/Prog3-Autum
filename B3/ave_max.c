#include <stdio.h>
#include <math.h>
#include "ave_max.h"
#define MAX 32

int array_scan(int a[ ])
{
    int i = 0;
    while (scanf("%d", &a[i]) != EOF)
    {
        i++;
    }
    return i;
}
void array_ave_max(int n, int a[ ], double *ave, int *max)
{
    int i;
    int sum = 0;
    *max = a[0];
    for (i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
    *ave = (double)sum / n;
}