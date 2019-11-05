#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpn_calc.h"

//verifier le string
//error only one arug
//error operator = digit - 1

//create a pille
t_node *push_list(int data, t_node *head)
{
    t_node *new_head;

    if (!(new_head=malloc(sizeof(t_node))))
        return NULL;
    new_head->data = data;
    new_head->next = head;
    return (new_head);
}

t_node *pop_head(t_node *head)
{
    t_node *new_head;

    if(!head)
        return NULL;
    new_head = head->next;
    free(head);
    return (new_head);
}

int rpn_calc(char *str)
{
    t_node *head = NULL;

    while (*str)
    {
        if(is_space(*str))
            str++;
        if(is_digit(*str))
        {
            head = push_list(atoi(str), head);
            while(is_digit(*str))
                str++;
        }
        if(is_operator(*str))
        {
            head->next->data = calculate(head->next->data, head->data, *str);
            head = pop_head(head);
            str++;
        }
    }
    return (head->data);
}

// le programme n'a pas géré les errors
int main()
{
    char *str = "1 2 * 3 * 4 +";
    int r = rpn_calc(str);
    printf("%d\n", r);
    return 0;
}
