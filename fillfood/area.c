#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

char **make_area(char **tab, int x, int y)
{
    int i = 0;
    char **area;

    area = malloc(sizeof(char *) * y);
    while(i < y)
    {
        int j = 0;
        area[i]= malloc(sizeof(char) * (x));
        while (j < x)
        {
            area[i][j] = tab[i][j];
            j++;
        }
        area[i][j] = 0;
        i++;
    }
    return (area);
}

void print_tab(char **tab, t_point size)
{
    int i = -1;
   
    int x = size.col;
    int y = size.row;
    
    while (++i < y)
    {
       int j = -1;
        while(++j < x)
            printf("%c ",tab[i][j]);
        printf("\n");
    }
}

