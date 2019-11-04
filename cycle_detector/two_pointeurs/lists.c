#include <stdlib.h>
#include <stdio.h>
#include "floyd.h"

t_item     *item_init(int data)
{
    t_item *head;

    if (!(head = malloc(sizeof(t_item))))
        return NULL;
    head->data = data;
    head->next = NULL;
    return (head);
}

t_item     *push(t_item *head, int data)
{
    t_item *new;
    t_item *tete;

    tete = head;
    if (!(new = malloc(sizeof(t_item))))
        return NULL;
    new->data = data;
    new->next = NULL;
    while(tete->next)
    {
        tete = tete->next;
    }
    tete->next = new;
    return (head);
}

t_item     *connection(t_item *head)
{
    t_item *tmp;
    t_item *tete;
    tete = head;
    tmp = head->next;
    while(tete->next)
    {
        tete = tete->next;
    }
    tete->next = tmp;
    return head;
}

t_item     *circle()
{
    int i = 1;
    t_item *head = item_init(15);
    while(i < 5)
    {
        head = push(head, 15-i);
        i++;
    }
    head = connection(head);
    return head;
}
/*
int main()
{
    int i = 0;
    t_item *head = circle();
    while(i < 20)
    {
        printf("%d\n", head->data);
        head = head ->next;
        i++;
    }
}
*/