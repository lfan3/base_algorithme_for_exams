#include <stdlib.h>
#include <stdio.h>
#include "pcal.h"

int calculate(int a, int b, char c)
{
    int result;
    if (c == '+')
        result = a + b;
    else if (c == '-')
        result = a - b;
    else if (c == '*')
        result = a * b;
    else if (c == '/')
        result = a / b;
    else
        result = a % b;
    return (result);
}

t_t *read(char *str)
{
    int result;
    t_t *pile_head = NULL;

    while(*str)
    {
        if (is_espace(*str))
            str++;
        else if (is_digit(*str))
        {
            pile_head = push_pile(atoi(str), pile_head);
            while(is_digit(*str))
                str++;         
        }
        else if (is_operater(*str))
        {
            result = calculate(pile_head->next->data, \
                               pile_head->data, *str);
            pile_head->next->data = result;
            pile_head = pop_pile(pile_head);
            str++;
        }
    }
    return(pile_head);
}

int main()
{
    char *str = "5 10 9 / - 50 *";
    t_t *head = read(str);
   
   printf("%d\n", head->data);
}