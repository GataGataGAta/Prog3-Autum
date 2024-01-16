#include <stdio.h>
#include <string.h>

#define POOL_SIZE 512
#define WORD_MAX 32

char pool[POOL_SIZE];
char *word[WORD_MAX];
char *next = pool;

int main()
{
    char buffer[WORD_MAX];
    int word_count = 0;

    while (1)
    {
        printf("next word = ");
        if (scanf("%31s", buffer) == EOF)
        {
            break;
        }

        int len = strlen(buffer) + 1; 
        if (next - pool + len < POOL_SIZE && word_count < WORD_MAX)
        {
            strcpy(next, buffer);     
            word[word_count++] = next; 
            next += len;               
        }
        else
        {
            printf("エラー: プールサイズまたは単語の最大数を超えました。\n");
            break;
        }
    }

    printf("\npool    = (%p)\n", (void *)pool);
    for (int i = 0; i < word_count; i++)
    {
        printf("word[%d] = (%p) \"%s\"\n", i, (void *)word[i], word[i]);
    }
    printf("next    = (%p)\n", (void *)next);

    return 0;
}
