#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myrand(void)
{
    static unsigned long r = 53402397UL;
    r = (65539UL * r + 125654UL) & 0x7fffffffUL;
    return r / (double)0x80000000UL;
}

double generate_normal_random(double mean, double stddev)
{
    double u1 = myrand();
    double u2 = myrand();
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0 * stddev + mean;
}

int main()
{
    double mean, stddev;
    int num_students, i;
    printf("平均点、標準偏差、受験者数を入力してください: ");
    scanf("%lf %lf %d", &mean, &stddev, &num_students);

    double sum = 0, sq_sum = 0;
    int frequency[21] = {0};

    for (i = 0; i < num_students; i++)
    {
        double score = generate_normal_random(mean, stddev);
        score = round(score);
        if (score < 0)
        {
            score = 0;
        }
        else if (score > 100)
        {
            score = 100;
        }

        sum += score;
        sq_sum += score * score;
        frequency[(int)score / 5]++;
    }

    double avg = sum / num_students;
    double variance = (sq_sum / num_students) - (avg * avg);
    double sd = sqrt(variance);

    printf("平均: %f\n", avg);
    printf("標準偏差: %f\n", sd);
    printf("度数分布（5点刻み）:\n");
    for (i = 0; i < 21; i++)
    {
        printf("%3d-%3d: %d\n", i * 5, i * 5 + 4, frequency[i]);
    }

    return 0;
}
