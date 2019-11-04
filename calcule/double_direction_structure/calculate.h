#ifndef CALCULATE_H
# define CALCULATE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
    int            data;
    char           *str;
    struct s_list   *prev;
    struct s_list   *next;
}                   t_list;

int no_other_char(char *str);
int right_nb_opera(char *str);
int sign_at_right_position(char *str);
int no_error(char *str);
int nb_cases(char *str);
char *small_case(char *str);
t_list  *list_init(char *str, int size);
t_list  *fille_list_data(t_list *list);
int  compa_str(char *str, char *str2);
int  calculate(t_list *list);

#endif