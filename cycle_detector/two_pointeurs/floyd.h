#ifndef FLOYD_H
#define FLOYD_H

typedef struct s_item
{
    int            data;
    struct s_item *next;
}               t_item;

int     detector(t_item *list_head);
t_item     *circle();
#endif