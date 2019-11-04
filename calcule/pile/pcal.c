#include <stdlib.h>
#include <stdio.h>
#include "pcal.h"

t_t *push_pile(int data, t_t *head)
{
    t_t *tmp1 = head;
    if(!(head = malloc(sizeof(t_t))))
        return NULL;
    head->next = tmp1;
    head->data = data;
    return (head);
}

void *display_pile(t_t *head)
{
    while(head)
    {
        printf("head %d\n", head->data);
        head = head->next;
    }
}

t_t *pop_pile(t_t *head)
{
    t_t *to_free;

    to_free = head;
    head = head->next;
    free(to_free);
    return(head);
}
/*
int main()
{
    t_t *head;

    head = push_pile(5, head);
   
    display_pile(head);

    

    return 0;
}
*/

