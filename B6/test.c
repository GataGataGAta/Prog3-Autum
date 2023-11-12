#include<stdio.h>

void bubble_sort(int n, int a[])
{
    int i, j, p;
    p = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
                p++;
            }
        }
    }
    printf("%d\n", p);
}
void inserection_sort(int n, int a[])
{
    int i, j, p;
    p = 0;
    for (i = 1; i < n; i++)
    {
        int tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
        {
            a[j] = a[j - 1];
            p++;
        }
        a[j] = tmp;
    }
    printf("%d\n", p);
}

void selection_sort(int n, int a[])
{
    int i, j, p;
    int min;
    p = 0;
    for(i = 0; i <= n - 2; i++)
    {
        min = i;
        for(j = i + 1; j <= n - 1; j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        int tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
        p++;
    }
    printf("%d\n", p);
}

int main()
{
    int a[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    //bubble_sort(10, a);
    //inserection_sort(1000, a);
    selection_sort(10, a);
    for(i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

}