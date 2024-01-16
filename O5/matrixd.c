#include <stdio.h>
#include <stdlib.h>
#include "matrixd.h"

double *matrixd_new(int n)
{
    return (double *)malloc(n * n * sizeof(double));
}

void matrixd_delete(double *A)
{
    free(A);
}

void matrixd_print(int n, double *A)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%10.5f ", A[i * n + j]);
        }
        printf("\n");
    }
}

void matrixd_scan(int n, double *A)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf", &A[i * n + j]);
        }
    }
}

void matrixd_sum(int n, double *A, double *B, double *Y)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            Y[i * n + j] = A[i * n + j] + B[i * n + j];
        }
    }
}
