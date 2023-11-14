#include <stdio.h>
#include "str_sort.h"

void swapmin(int n, double *a, int k)
{
    int i, p;
    double min, tmp;
    p = 0;
    tmp = 0;
    min = 10000000000000000;
    for (i = k; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            p = i;
        }
    }
    tmp = a[k];
    a[k] = min;
    a[p] = tmp;
}

void sort(int n, double *a)
{
    int k;
    for(k = 0; k <= n-2; k++)
    {
        swapmin(n, a, k);
    }
}

void str_sort(int n, record_t *a)
{
    record_t x;
    int i, j;
    for(i = 0; i < n; i++)
    {
        strcpy(x, a[i]);
        for(j = i; 0 < j; j--)
        {
            if(strcmp(a[j - 1], x) <= 0)
            {
                break;
            }
            else
            {
                strcpy(a[j], a[j - 1]);
            }
        }
        strcpy(a[j], x);
    }



}