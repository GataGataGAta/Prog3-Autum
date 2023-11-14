#include <stdio.h>

void sort(int n, double *a)
{
    int left, right;
    double p;
    left = 0;
    right = n - 1;
    double tmp = 0.0;
    p = a[left];
    while(left <= right)
    {
        while (a[left] < p)
        {
            left++;
        }
        while (a[right] > p)
        {
            right--;
        }
        if(left <= right)
        {
            tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
            left++;
            right--;
        }
        
    }

    if(0 < right)
    {
        sort(right + 1, a);
    }

    if(left < n - 1)
    {
        sort(n - left, &a[left]);
    }

}