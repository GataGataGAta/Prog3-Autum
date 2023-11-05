#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pref1.h"

int main(void)
{
    pref_t *p[3] = {NULL, NULL, NULL};

    p[0] = pref_new("Tokyo", 2187.65, 12988797);
    p[1] = pref_new("Osaka", 1898.01, 8840372);
    p[2] = pref_new("Hyogo", 8395.89, 5599359);

   for(int i = 0; i < 3; i++)
   {
        pref_print(p[i]);
   }

    for(int j = 0; j < 3; j++)
    {
        free(p[j]);
        p[j] = NULL;
    }
    return 0;
}