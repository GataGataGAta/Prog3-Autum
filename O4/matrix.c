#include <stdio.h>
#include <assert.h>
#include "matrix.h"

/* 行列の出力 */
void matrix_print(int n, double A[N][N])
{
	int i, j;
	assert(n <= N);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf(" %.5f", A[i][j]);
		}
		printf("\n");
	}
}

void matrix_scan(int n, double A[N][N])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%lf", &A[i][j]);
		}
	}
}

void matrix_sum(int n, double A[N][N], double B[N][N], double Y[N][N])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Y[i][j] = A[i][j] + B[i][j];
		}
	}
}

void matrix_trans2(int n, double A[N][N], double Y[N][N])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Y[j][i] = A[i][j];
		}
	}
}

void matrix_trans1(int n, double A[N][N])
{
	int i, j, r;
	double tmp;
	r = 0;
	for (i = r; i < n; i++)
	{
		for (j = r; j < n; j++)
		{
			tmp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = tmp;
		}
		r++;
	}
}

void vector_scan(int n, double x[N])
{
	int i;
	for (i = 0; i < n; i++)
	{
		x[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%lf", &x[i]);
	}
}

void vector_print(int n, double x[N])
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf(" %.5f\n", x[i]);
	}
}

void matrix_vector_prod(int n, double A[N][N], double x[N], double y[N])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		y[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			y[i] += x[j] * A[i][j];
		}
	}
}

void matrix_copy(int n, double From[N][N], double To[N][N])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			To[i][j] = From[i][j];
		}
	}
}

void vector_copy(int n, double from[N], double to[N])
{
	for (int i = 0; i < n; ++i)
	{
		to[i] = from[i];
	}
}

void matrix_vector_print(int n, double A[N][N], double b[N])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%10.5f ", A[i][j]);
		}
		printf(": %10.5f\n", b[i]);
	}
}

void gauss_jordan(int n, double A[N][N], double b[N])
{
	for (int i = 0; i < n; ++i)
	{
		double div = A[i][i];
		for (int j = 0; j < n; ++j)
		{
			A[i][j] /= div;
		}
		b[i] /= div;

		for (int k = 0; k < n; ++k)
		{
			if (k != i)
			{
				double mul = A[k][i];
				for (int j = 0; j < n; ++j)
				{
					A[k][j] -= A[i][j] * mul;
				}
				b[k] -= b[i] * mul;
			}
		}

		printf("<%d行目>\n", i);
		matrix_vector_print(n, A, b);
	}
}
