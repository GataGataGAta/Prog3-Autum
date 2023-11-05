#include <stdio.h>
#include <string.h>

#define LINELEN 128
#define MAX 1000

int main(void)
{
    int c = 0;
    char s[MAX * (LINELEN + 1)];
    char *line[MAX];

    for (int i = 0; i < MAX; i++)
    {
        line[i] = s + i * (LINELEN + 1);
    }

    while (fgets(line[c], LINELEN, stdin) != NULL && c < MAX - 1)
    {
        c++;
    }

    if (c == MAX - 1)
    {
        fprintf(stderr, "入力が長すぎます。\n");
    }

    for (int i = c; i >= 0; i--)
    {
        printf("%s", line[i]);
    }
    return 0;
}
