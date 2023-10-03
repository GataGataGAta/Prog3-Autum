#include <stdio.h>

#define numbers 5
#define cards 13

int main(void)
{
    int n[numbers];
    int c[cards];
    int i, j;
    for (i = 0; i < cards; i++)
    {
        c[i] = 0;
    }
    for (i = 0; i < numbers; i++)
    {
        n[i] = 0;
    }

    i = 0;
    for (;;)
    {
        fprintf(stderr, "整数を入力してください:");
        for (i = 0; i < numbers; i++)
        {
            if (scanf("%d", &n[i]) == EOF)
            {
                return 0;
            }
            c[n[i]]++;
        }

        int fc = 0; // 4カードを判定する変数
        int fh = 0; // フルハウスを判定する変数
        int tc = 0; // 3カードを判定する変数
        int tp = 0; // 2ペアを判定する変数
        int op = 0; // 1ペアを判定する変数

        for (i = 0; i < cards; i++)
        {
            if (c[i] == 4)
            {
                fc = 1;
                break;
            }

            else if (c[i] == 3)
            {
                tc = 1; // 3枚揃った段階
                for (j = 0; j < cards; j++)
                {
                    if (i != j && c[j] == 2)
                    {
                        fh = 1; // フルハウスの判定
                        break;
                    }
                }
            }

            else if (c[i] == 2)
            {
                op = 1; // 1ペアは確定
                for (j = 0; j < cards; j++)
                {
                    if (j != i && c[j] == 2)
                    {
                        tp = 1; // 2ペアの判定
                        break;
                    }
                }
            }
        }

        if (fc == 1)
        {
            printf("four of a kind\n");
        }
        else if (tc == 1 && fh == 0)
        {
            printf("three of a kind\n");
        }

        else if (fh == 1)
        {
            printf("full house\n");
        }
        else if (tp == 1)
        {
            printf("two pair\n");
        }

        else if (tp == 0 && op == 1)
        {
            printf("one pair\n");
        }

        else
        {
            printf("no pair\n");
        }

        for (i = 0; i < cards; i++)
        {
            c[i] = 0;
        }
        for (i = 0; i < numbers; i++)
        {
            n[i] = 0;
        }
    }

    return 0;
}