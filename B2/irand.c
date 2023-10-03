#include <stdio.h>
#include <stdlib.h>

int irand(int a, int b);

int main(void)
{
    int a, b, i, n;
    int ran;
    printf("a, b, nの値を入力してください:");
    scanf("%d %d %d", &a, &b, &n);
    int c[b - 1];

    for(i = a; i <= b; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < n; i++) 
    {
        ran = irand(a, b);
        printf("%d\n", ran);
        c[ran]++;
    }
    for(i = a; i <= b; i++)
    {
        printf("%dが出現した回数:%d\n", i, c[i]);
    }

    return 0;
}

int  irand(int a, int b)
{
    return a + (int)(rand() * (b - a + 1.0) / (1.0 + RAND_MAX));
}