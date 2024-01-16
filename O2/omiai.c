#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generate_level(int distribution[])
{
    int r = rand() % 10;
    for (int i = 0; i < 5; i++)
    {
        if (r < distribution[i])
            return i + 1;
        r -= distribution[i];
    }
    return 5;
}

int x_accept(int c, int y)
{
    return 1;
}

int main()
{
    srand(time(NULL));
    int distribution[5] = {1, 2, 4, 2, 1};
    int total_success = 0, total_level = 0;

    for (int i = 0; i < 100; i++)
    {
        int x = generate_level(distribution);
        int success = 0, level = -5;

        for (int c = 0; c < 15; c++)
        {
            int y = generate_level(distribution);
            if (x_accept(c, y) == 1)
            {
                double p = (0.19 * x) * (1.1 - 0.1 * y);
                if (rand() % 1000 < p * 1000)
                {
                    success = 1;
                    level = y;
                    break;
                }
            }
        }

        total_success += success;
        if (success)
        {
            total_level += level;
        }
        else
        {
            total_level -= 5;
        }
    }

    printf("結婚できる確率: %f\n", total_success / 100.0);
    printf("結婚できる相手のレベルの期待値: %f\n", total_level / 100.0);
    return 0;
}
