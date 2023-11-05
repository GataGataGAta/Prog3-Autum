#include <stdio.h>
#include <stdlib.h>

int* new_array_scan(int *pn);

int main(void)
{
    int *a = NULL;
    int *b = NULL;
    int i, n;

    a = new_array_scan(&n);
    int max = a[0];
    int min = a[0];
    for(i = 0; i < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
        if(min > a[i])
        {
            min = a[i];
        }
    }
    
    b = (int*)malloc(sizeof(int)*(max - min + 1));
    for(i = 0; i < max - min + 1; i++)
    {
        b[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        b[a[i] - min]++;
    }

    for(i = 0; i < max - min + 1; i++)
    {
        if(b[i] > 0)
        {
            printf("%d: %d\n", i + min, b[i]);
        }
    }

    free(a);
    a = NULL;
    free(b);   
    b = NULL;

    return 0;
}