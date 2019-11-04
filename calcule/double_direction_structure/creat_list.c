#include "calculate.h"

int nb_cases(char *str)
{
    int len = 0;
    while (*str)
    {
        if (*str == ' ')
            len++;
        str++;
    }
    return (len+1);
}

char *small_case(char *str)
{
    int len = 0;
    int i = 0;
    char *insider;

    while (str[len] != ' ' && str[len])
        len++;
    if (!(insider = (char *)malloc(sizeof(char) * len)))
        return NULL;
    insider[len] = 0;
    while (i < len)
    {
        insider[i] = str[i];
        i++;
    }
    return (insider); 
}


t_list  *list_init(char *str, int size)
{
    t_list *begin;
    t_list *lst;
    int i = 0;
    int n = 0;
    int k = 0;

    if(!(begin = malloc(sizeof(t_list))))
        return NULL;
    lst = begin;
    begin->prev = NULL;
    while (i < size)
    {
        if (str[n])
        {
            begin->str = small_case(str + k);
            begin->data = 0;           
            if (str[n + 1])
            {
                if(!(begin->next = malloc(sizeof(t_list))))
                    return NULL;
                begin->next->prev = begin;
                begin = begin->next;
            }
            else
                begin->next = NULL;
        }
        while (str[n] != ' ' && str[n])
            n++;
        n++;
        k = n;
        i++;    
    }
    return lst;
}

// list with no data, or data = 0
t_list     *fille_list_data(t_list *list)
{
    t_list *begin;
    
    begin = list;
    while (list)
    {
        list->data = atoi(list->str);
        list = list->next;
    }
    return begin;
}

