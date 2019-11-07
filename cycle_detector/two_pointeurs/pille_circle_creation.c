#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"

static t_item  *pille_push(int next_data, t_item *head)
{
    t_item *new_head;

    if(!(new_head = malloc(sizeof(t_item))))
        return NULL;
    new_head->data = next_data;
    new_head->next = head;
    return (new_head);
}

t_item *create_lineral_liste(t_item *head, int *data_tab, int date_table_len)
{
    int i =  date_table_len;
    while (--i >= 0)
        head = pille_push(data_tab[i], head);
    return (head);
}

static t_item *link_head_to_tail(t_item *head)
{
    t_item *tmp;
    
    tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = head;
    return (head);
}

t_item *circle_creator(t_item *head, int *tab, int data_tab_len)
{
    head = create_lineral_liste(head, tab, data_tab_len);
    head =  link_head_to_tail(head);
    return (head);
}


