#ifndef PCAL_H
#define PCAL_H

typedef struct s_s
{
    int data;
    struct s_s *next;
}              t_t;

int is_espace(char c);
int is_digit(char c);
int is_operater(char c);
t_t *push_pile(int data, t_t *head);
t_t *pop_pile(t_t *head);
t_t *read(char *str);


#endif