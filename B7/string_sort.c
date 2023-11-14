#include <stdio.h>
#include <string.h>
#include "string_sort.h"


void string_sort(int n, char (*a)[STRLEN + 1])
{
    char x[STRLEN + 1];
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