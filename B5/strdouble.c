#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdouble(char c[])
{
    char* clone = NULL;
    int i;

    clone = (char*)malloc(sizeof(char) * (strlen(c) * 2 + 1));

    for (i = 0; c[i] != '\0'; i++)
    {
        clone[i] = c[i];
    }
    for (i = 0; c[i] != '\0'; i++)
    {
        clone[i + strlen(c)] = c[i];
    }
    clone[i + strlen(c)] = '\0';

    return clone;
}