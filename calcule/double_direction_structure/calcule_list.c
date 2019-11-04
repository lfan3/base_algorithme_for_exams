#include "calculate.h"

int     compa_str(char *str, char *str2)
{
    int i = 0;
    while (*(str) || *(str2))
    {
        if (*str != *str2 || !str || !str2)
            return (0);
        str++;
        str2++;
    }
    return (1);
}

int     calculate(t_list *list)
{
    int i = 0;
    int tmp;
    int result;
    t_list *begin;
    begin = list;
//memory?
    while(list && !(list->next == NULL && list->prev == NULL))
    {

        if (compa_str(list->str, "+") || compa_str(list ->str, "-") \
            || compa_str(list ->str, "*") \
            || compa_str(list ->str, "/") || compa_str(list->str, "%"))
            {
                if(list->prev != NULL && list->prev->prev != NULL && compa_str(list->str, "+"))
                    list->prev->prev->data = (list->prev->data) + (list->prev->prev->data);
                else if(list->prev != NULL && list->prev->prev != NULL && compa_str(list->str, "-"))
                    list->prev->prev->data = (list->prev->prev->data) - (list->prev->data);
                else if(list->prev != NULL && list->prev->prev != NULL && compa_str(list->str, "*"))
                    list->prev->prev->data = (list->prev->data) * (list->prev->prev->data);
                else if(list->prev != NULL && list->prev->prev != NULL && compa_str(list->str, "/"))
                    list->prev->prev->data = (list->prev->prev->data) / (list->prev->data);
                else if(list->prev != NULL && list->prev->prev != NULL && compa_str(list->str, "%"))
                    list->prev->prev->data = (list->prev->prev->data) % (list->prev->data);            
                if (list->next != NULL)
                {
                    list->prev->prev->next = list->next;
                    list->next->prev = list->prev->prev;
                }
                else{
                    list->prev->prev->next = NULL;
                }             

                list = list->prev->prev;            
            }
        else
            list = list->next;
    }
   
    if(list->prev == NULL)
        return (list->data);
    return 0;
}

int main(int ac, char **av)
{
    int i = -1;
    int c;
    int b;
    t_list *list;
    t_list *begin;

    if (ac != 2)
    {
        printf("\n");
        return (0);
    }
   
    c = no_error(av[1]);
    if (c == 1)
        b = nb_cases(av[1]);
    else
    {
        printf("Error\n");
        return 0;
    }
   
    list = list_init(av[1], b);  
    list = fille_list_data(list);
    begin = list;

    int result = calculate(begin);
    printf("result %d\n", result);
    return 0;


    return 0;
}
