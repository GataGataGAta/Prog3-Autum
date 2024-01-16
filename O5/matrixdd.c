#include "matrixdd.h"
#include <stdio.h>
#include <stdlib.h>

double **matrixdd_new(int n)
{
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; ++i)
    {
        A[i] = (double *)malloc(n * sizeof(double));
    }
    return A;
}

void matrixdd_delete(int n, double **A)
{
    for (int i = 0; i < n; ++i)
    {
        free(A[i]);
    }
    free(A);
}

void matrixdd_print(int n, double **A)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%10.5f ", A[i][j]);
        }
        printf("\n");
    }
}

void matrixdd_scan(int n, double **A)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lf", &A[i][j]);
        }
    }
}

void matrixdd_sum(int n, double **A, double **B, double **Y)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            Y[i][j] = A[i][j] + B[i][j];
        }
    }
}
