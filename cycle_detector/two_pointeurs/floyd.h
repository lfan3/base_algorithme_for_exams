#ifndef FLOYD_H
#define FLOYD_H

typedef struct s_item
{
    int            data;
    struct s_item *next;
}               t_item;

int     circle_detector(t_item *list_head);
t_item     *circle();
t_item *create_lineral_liste(t_item *head, int *data_tab, int date_table_len);
t_item *circle_creator(t_item *head, int *tab, int data_tab_len);
#endif