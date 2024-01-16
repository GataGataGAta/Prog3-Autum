#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[5];
    int count[14] = {0}; 

    while (scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]) != EOF)
    {
        for (int i = 0; i < 14; i++)
        {
            count[i] = 0;
        }

        for (int i = 0; i < 5; i++)
        {
            count[numbers[i]]++;
        }

        int pairs = 0;
        int three = 0;
        int four = 0;

        for (int i = 1; i <= 13; i++)
        {
            if (count[i] == 4)
            {
                four = 1;
            }
            else if (count[i] == 3)
            {
                three = 1;
            }
            else if (count[i] == 2)
            {
                pairs++;
            }
        }

        if (four == 1)
        {
            printf("four of a kind\n");
        }
        else if (three == 1&& pairs == 1)
        {
            printf("full house\n");
        }
        else if (three == 1)
        {
            printf("three of a kind\n");
        }
        else if (pairs == 2)
        {
            printf("two pair\n");
        }
        else if (pairs == 1)
        {
            printf("one pair\n");
        }
        else
        {
            printf("no pair\n");
        }
    }

    return 0;
}
