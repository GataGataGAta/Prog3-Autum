#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define Top 10
#define MAX 255

int main(void)
{
    int n, i;
    double result = 0;
    fprintf(stderr, "品物の種類を入力:");
    scanf("%d", &n);
    double weight[Top];
    int count[Top];

     for(int j = 0; j < n; j++)
     {
         count[j] = 0;
         //printf("%d\n", count[j]);
     }

    for(i = 0; i < n; i++)
    {
        fprintf(stderr, "点数を入力してください:");
        scanf("%lf", &weight[i]);
    }

    i = 0;
    for (;;)
    {
        fprintf(stderr, "系列を入力してください:");
        if (scanf("%d", &i) == EOF)
        {
            break;
        }
        count[i]++;
    }
    
    for(i = 0; i < n; i++)
    {
        result += count[i] * weight[i];
    }

    printf("%0.1lf\n", result);

    // for(i = 0; i < n; i++)
    // {
    //     printf("%d %lf %d\n", i, weight[i], count[i]);
    // }
}