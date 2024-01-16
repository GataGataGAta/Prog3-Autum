#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void sort(int n, double *a)
{
    double min = DBL_MAX, max = -DBL_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    int B = 8;    
    int m = n / B; 
    if (n % B != 0)
        m++;
    double range = max - min;
    double interval = range / m;

    int *c = (int *)calloc(m, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int k = (int)((a[i] - min) / interval);
        if (k >= m)
            k = m - 1; 
        c[k]++;
    }

    int *d = (int *)malloc((m + 1) * sizeof(int));
    d[0] = 0;
    for (int i = 0; i < m; i++)
    {
        d[i + 1] = d[i] + c[i];
    }

    double *b = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
    {
        int k = (int)((a[i] - min) / interval);
        if (k >= m)
            k = m - 1; 
        b[d[k]] = a[i];
        d[k]++;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }

    for (int i = 1; i < n; i++)
    {
        double tmp = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > tmp)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = tmp;
    }

    free(b);
    free(c);
    free(d);
}

//
