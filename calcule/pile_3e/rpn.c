#include <stdio.h>
#include <stdlib.h>
#include "rpn.h"

void push_list(int data, t_t **head)
{
    t_t *tmp;

    tmp = (*head);
    if(!(*head = malloc(sizeof(t_t))))
        return;
    (*head)->data = data;
    (*head)->next = tmp;
}

void pop_list(t_t **head)
{
    t_t *to_free;
    to_free = *head;
//?? change the positjion to see what will happen
    *head = (*head)->next;

    free(to_free);
}

int main()
{
    int a = 2;
    int b = 3;
    t_t *head = NULL;
    t_t **tete = &head;
    push_list(a, tete);
    push_list(b, tete);
    printf("befonre changement %d %d\n",(*tete)->data,(*tete)->next->data);
    pop_list(tete);
    printf("after the changement %d\n",(*tete)->data);

    return 0;
}