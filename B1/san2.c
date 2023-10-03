#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n;
    fprintf(stderr, "1から99までの整数を入力してください>>>");
    scanf("%d", &n);

    if(n < 1 || n > 99)
    {
        fprintf(stderr, "1から99までの整数を入力してください>>>");
    }

    for(int i = 0; i < n; i++)
    {
        int j = i % 10;
        int k = i / 10;
        if(i % 3 == 0 || j == 3 || k == 3)
        {
            if(i != 0)
            {
            printf("%d\n", i);
            }
        }
    }
    
    
    return 0;

}
