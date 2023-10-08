#include <stdio.h>
#include <string.h>

#define NM_LEN 31

typedef struct
{
    char name[NM_LEN + 1]; /* 名前 */
    double stature;        /* 身長 [cm] */
    double weight;         /* 重量 [kg] */
    double bmi;            /* BMI値 */
} body_index_t;

void body_index_print(body_index_t x);

double bmi(body_index_t x);

int main(void)
{
    body_index_t p;
    for(;;)
    {
    fprintf(stderr, "名前を入力してください:");
    scanf("%s", p.name);
    if (strcmp(p.name, "q") == 0)
    {
        break; 
    }
    fprintf(stderr, "身長を入力してください:");
    scanf("%lf", &p.stature);
    fprintf(stderr, "体重を入力してください:");
    scanf("%lf", &p.weight);
    p.bmi = bmi(p);

    body_index_print(p);
    }
}

void body_index_print(body_index_t x)
{
    printf("name: %s\n", x.name);
    printf("stature: %0.1fcm\n", x.stature);
    printf("weight: %0.1fkg\n", x.weight);
    printf("BMI: %0.1f\n", x.bmi);
}

double bmi(body_index_t x)
{
    return x.weight / (0.01 * x.stature * 0.01 * x.stature);
}