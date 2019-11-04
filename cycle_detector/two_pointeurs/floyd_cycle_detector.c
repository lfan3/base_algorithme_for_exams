#include "floyd.h"
#include <stdio.h>

int     detector(t_item *list_head)
{
    t_item *ptr1;
    t_item *ptr2;

    ptr1 = list_head;
    ptr2 = list_head;
    while(list_head)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
        if(ptr1 == ptr2)
            return(1);
        list_head = list_head->next;
    }
    return 0;
}