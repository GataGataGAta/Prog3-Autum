#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Count 3

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void)
{
    char filename[] = "out.txt";

    FILE *fp = fopen(filename, "w");
    if(fp == NULL)
    {
        printf("ERROR");
        exit(EXIT_FAILURE);
    }
    
    double x1, y1, x2, y2, result;
    for(int i = 0; i < Count; i++)
    {
    fprintf(stderr, "実数を四つ入力してください>>>");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    result = dist(x1, y1, x2, y2);
    fprintf(fp, "%.4f\n", result);
    }

    fclose(fp);
    return EXIT_SUCCESS;

}
