#ifndef T_POINT_H
# define T_POINT_H

typedef struct s_point {
	int		col;
	int 	row;
}				t_point;

char **make_area(char **tab, int x, int y);
void print_tab(char **tab, t_point size);

#endif
