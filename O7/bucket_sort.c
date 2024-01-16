#include <stdio.h>
#include <stdlib.h>

void insertion_sort(double *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        double key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void sort(int n, double *a)
{
    double min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    int B = 8; 
    int m = n / B;
    if (n % B != 0)
    {
        m++;
    }
    double **buckets = (double **)malloc(m * sizeof(double *));
    int *bucketSizes = (int *)calloc(m, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int index = (int)((a[i] - min) / (max - min) * (m - 1));
        bucketSizes[index]++;
    }

    for (int i = 0; i < m; i++)
    {
        buckets[i] = (double *)malloc(bucketSizes[i] * sizeof(double));
        bucketSizes[i] = 0; 
    }

    for (int i = 0; i < n; i++)
    {
        int index = (int)((a[i] - min) / (max - min) * (m - 1));
        buckets[index][bucketSizes[index]++] = a[i];
    }

    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        insertion_sort(buckets[i], bucketSizes[i]);
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            a[idx++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}