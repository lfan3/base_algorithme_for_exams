#include <stdio.h>
#include <unistd.h>
#include "biggest_pal.h"

void    biggest_pal_obb_even(char *str)
{
    int counter = 1;
    int i = 0;
    int j;
    int len;
    int maxL;
    int maxLO=1;
    int maxLE=1;
    int startO;
    int startE;
    int endO;
    int endE;

    len = get_len(str);

    int start= len-1;
    int end=len -1;
// obb
    while (++i < len - 1)
    {
        counter = 1;
        while( str[i + counter] == str[i - counter] && (i - counter) >= 0 \
            && (i + counter) <= len - 1 )
        {
            if (maxLO < 2 * counter + 1)
            {
                maxLO = 2*counter+1;
                startO = i-counter;
                endO = i + counter;
            }
            counter++;
        }
    }
// even
    i = 0;
    while (++i < len - 1)
    {
        j = i+1;
        counter = 1;
        while( str[i] == str[j] && str[j + counter] == str[i - counter] \
            && (i - counter) >= 0 && (j + counter) <= len - 1 )
        {
            if (maxLE < 2 * counter + 2)
            {
                maxLE = 2*counter+2;
                startE = i-counter;
                endE = j + counter;
            }
            counter++;
        }
    } 
//comparaison entre obb et even
    if (maxLE > maxLO)
    {
        maxL = maxLE;
        start = startE;
        end = endE;
    }  
    else
    {
        maxL = maxLO;
        start = startO;
        end = endO; 
    }
    affichier_pal(str, start, end);
}

