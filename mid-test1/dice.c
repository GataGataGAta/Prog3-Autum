#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d", &a);
    int b[a];

    for(int n = 0; n < a; n++)
    {
        b[n] = rand()% 6 + 1;
    }

    for(int n = 0; n < a; n++)
    {
        printf("%d: %d\n", n, b[n]);
    }
}
