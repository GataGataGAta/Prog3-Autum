#include <stdio.h>

void sort(int n, double *a)
{
    int k;
    int i;
    double tmp;
    for (k = 1; k <= n - 1; k++)
    {
        for (i = k; 1 <= i; i--)
        {
            if (a[i - 1] <= a[i])
            {
                break;
            }
            else
            {
                tmp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = tmp;
            }
        }
    }
}
