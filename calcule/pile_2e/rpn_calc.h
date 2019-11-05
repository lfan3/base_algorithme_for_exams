#ifndef RPN_CALC_H
#define RPN_CALC_H

typedef struct  s_node
{
    int data;
    struct s_node *next;
}               t_node;

t_node *push_list(int data, t_node *head);
t_node *pop_head(t_node *head);
int rpn_calc(char *str);
int is_space(char c);
int is_digit(char c);
int is_operator(char c);
int calculate(int a, int b, char c);
#endif