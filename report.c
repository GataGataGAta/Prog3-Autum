#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STUDENT_NAME "山形 隼士"

void divide(int x, FILE *fp);
void each_problem(int x, int y, FILE *fp);

int main(void)
{

    int number_of_class;
    printf("type the number of class -> ");
    scanf("%d", &number_of_class);

    char dir_path[10], file_path[15];
    sprintf(dir_path, "./B%d", number_of_class);
    sprintf(file_path, "%s/B%d.txt", dir_path, number_of_class);

    if (mkdir(dir_path, 0755) == -1)
    {
        perror("mkdir error");
    }

    FILE *fp = fopen(file_path, "w");
    if (!fp)
    {
        fprintf(stderr, "cannot open %s\n", file_path);
        return 1;
    }

    int month, day;
    printf("type the month and day -> ");
    scanf("%d %d", &month, &day);

    fprintf(fp, "科目名: プログラミング実習III\n課題: B%d\n番号: 37022503\n氏名: %s\n作成: 2023/%d/%d\n\n", number_of_class, STUDENT_NAME, month, day);
    divide(40, fp);

    int number_of_problem;
    printf("type the number of problem -> ");
    scanf("%d", &number_of_problem);
    each_problem(number_of_class, number_of_problem, fp);

    fprintf(fp, "[課題 B%d の感想]\n", number_of_class);
    
    fclose(fp);
    return 0;
}

void divide(int x, FILE *fp)
{
    for (int i = 0; i < x; i++)
    {
        fprintf(fp, "-");
    }
    fprintf(fp, "\n");
}

void each_problem(int x, int y, FILE *fp)
{
    for (int i = 0; i < y; i++)
    {
        fprintf(fp, "[課題%d.%d]\n[課題の内容]\n〇〇を作成した。\n\n[実行結果]\n[考察]\n[工夫した箇所]\n", x, i+1);
        divide(40, fp);
    }
}