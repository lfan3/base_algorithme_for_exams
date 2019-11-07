#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"

//why i call it improuved version
//because the old circle_detector did not consider the liste without circle.

int circle_detector(t_item *head)
{
    t_item *p_slow;
    t_item *p_fast;

    p_slow = head;
    p_fast = head;
    //very important this condition, the p_fast and p_fast->next must exite
    //i wrote p_fast->next->next, this poiteur can already not existed ->segmentation fault
    while(head && p_fast && (p_fast->next))
    {
        p_slow = p_slow->next;
        p_fast = p_fast->next->next;
        if(p_fast == p_slow)
            return 1;
        head = head->next;
    }
    return 0;
}