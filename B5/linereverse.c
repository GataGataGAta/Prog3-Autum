#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINELEN 128
#define MAX 1000

int main(void)
{
    int c = 0;
    char s[MAX * (LINELEN + 1)];
    char *line[MAX];

    for (int i = 0; i < MAX; i++)
    {
        line[i] = malloc((LINELEN + 1) * sizeof(char));
        if (line[i] == NULL)
        {
            fprintf(stderr, "メモリの割り当てに失敗しました。\n");
            return 1;
        }
    }

    while (fgets(s, LINELEN, stdin) != NULL && c < MAX - 1)
    {
        strcpy(line[c], s);
        c++;
    }

    if (c == MAX - 1)
    {
        fprintf(stderr, "入力が長すぎます。\n");
    }

    for (int i = c; i >= 0; i--)
    {
        printf("%s", line[i]);
        free(line[i]); 
    }
    return 0;
}