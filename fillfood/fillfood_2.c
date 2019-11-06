#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

void flood_fill_exec(char **tab, t_point size, int x, int y, char to_replace)
{
    int max_x = size.row;
    int max_y = size.col;
    if(x >= max_x || y >= max_y || x < 0 || y < 0 || tab[x][y] != to_replace)
        return;
    else
    {
        tab[x][y]= 'F';
        //4 direcitons
        flood_fill_exec(tab,size,x+1, y, to_replace);
        flood_fill_exec(tab,size,x, y+1, to_replace);
        flood_fill_exec(tab,size,x, y-1, to_replace);
        flood_fill_exec(tab,size,x-1, y, to_replace);
    }
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char to_replace;
    int x = begin.row;
    int y = begin.col;
   
    to_replace = tab[x][y];
    flood_fill_exec(tab,size,x,y,to_replace);
}


int main(void)
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 7, 2 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	area = make_area(zone, size.col, size.row);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}