#include <stdio.h>

int main(void)
{
    int k, n, m;
    fprintf(stderr, "整数を入力してください:");
    scanf("%d", &k);
    int a[k];

    for (int i = 0; i < k; i++)
    {
        a[i] = 0;
    }

    fprintf(stderr, "数列の要素を入力してください:");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &a[i]);
    }

    fprintf(stderr, "nを入力してください:");
    scanf("%d", &n);

    fprintf(stderr, "mを入力してください:");
    scanf("%d", &m);

    int b[n];

    for (int j = 0; j < n; j++)
    {
        b[j] = 0;
    }

    for (int p = 0; p < m; p++)
    {
        fprintf(stderr, "%d個の整数を入力してください:", n);
        for (int q = 0; q < n; q++)
        {
            scanf("%d", &b[q]);
        }

        // for(int q = 0; q < n; q++)
        // {
        //     printf("%d ", b[q]);
        // }
        // printf("\n");
        //確認用に配列bを出力しています

        int found = 0;
        for (int i = 0; i <= n - k; i++)
        {
            int match = 1;
            for (int j = 0; j < k; j++)
            {
                if (b[i + j] != a[j])
                {
                    match = 0;
                    break;
                }
            }
            if (match == 1)
            {
                found = 1;
                break;
            }
        }
        printf("%d\n", found);
    }
    return 0;
}