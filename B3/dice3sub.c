#include <stdio.h>
#include <stdlib.h>
#define N_MAX 1024
#define D3_MIN (1+1+1)
#define D3_MAX (6+6+6)

int  irand(int a, int b)
{
    return a + (int)(rand() * (b - a + 1.0) / (1.0 + RAND_MAX));
}
void dice_throw(int d[ ], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        d[i] = irand(1, 6);
    }
}
void dice3_distr(int n, int d1[ ], int d2[ ], int d3[ ], int c[ ])
{
    int i, j;
    j = 0;
    for(int k = 0; k < n; k++)
    {
        c[k] = 0;
    }
    for(i = 0; i < n; i++)
    {
        j = d1[i] + d2[i] + d3[i];
        c[j]++;
    }
}