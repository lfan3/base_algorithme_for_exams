#include <stdio.h>
#include <stdlib.h>
#include "t_point_h"
void    flood_fill_until(char **tab, int size_x, int size_y, char to_replace, int begin_x, int begin_y)
{
        t_point size = { 8, 5 };
        char c = 'f';

    
    int x = begin_x;
    int y = begin_y;
    if (x >= size_x || x < 0 || y >= size_y || y < 0)
        return;
    if (tab[y][x] != to_replace)
        return;
    tab[y][x] = 'F';
   flood_fill_until(tab, size_x, size_y, to_replace, (x-1), y);
  flood_fill_until(tab, size_x, size_y, to_replace, x, (y-1));
  flood_fill_until(tab, size_x, size_y, to_replace, (x+1), y);
    flood_fill_until(tab, size_x, size_y, to_replace, x, (y+1));
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    int x = begin[0] - 1;
    int y = size[1] - begin[1];
    
    char to_replace = tab[y][x];
    flood_fill_until(tab, size[0], size[1], to_replace, x, y);
}

char **create_area(char **tab, t_point size)
{
    int i = 0;
    int x = size[0];
    int y = size[1];
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

int main(void)
{
    //what i have learned from this subject
    //local varialbe like char[5][8], can not be returned, only static variable, globale variable or malloc on heap can be seen by others
    // char zone[5][8], call by fonction(zone), the fonciton should be defined as void fonction(char zone[][8])
    // how to declare an array of poiteurs char *zone[] = .... 
    // caracters of array of pointeurs: 
    //*** each caracter inside a string can be vu with zone[2][1], but can not be modified like zone[2][1] = 'c';

    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001"
    };
    print_tab(zone, size);
    area = create_area(zone, size);
    flood_fill(area, size, begin);
    print_tab(area, size);
    return (0);
}
