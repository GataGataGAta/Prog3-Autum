#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pref.h"

#define MAX_PREF 47

int main(void)
{

    pref_t *prefs[MAX_PREF];
    int count = 0;

    for (int i = 0; i < MAX_PREF; i++)
    {
        prefs[i] = NULL;
    }

    while ((prefs[count] = pref_new_scan()) != NULL && count < MAX_PREF)
    {
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s %.2f %d\n", prefs[i]->name, prefs[i]->area, prefs[i]->population);
    }

    for (int i = 0; i < count; i++)
    {
        free(prefs[i]);
        prefs[i] = NULL;
    }

    return 0;
}
