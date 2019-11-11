#include <stdio.h>
#include "ft_list.h"
void ft_print_number(void *data)
{
    int *da = (int*)data;
    printf("%d\n", *da);
}
// type of the function and variable should be the same
// so void function to void function
// f(void *data) to (*f)(void *)
void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while(begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}

int main()
{
    t_list list1;
    t_list list2;
    t_list list3;
    int tab1[1] = {1};
    int tab2[1] = {2};
    int tab3[1] = {3};

    list1.data = tab1;
    list2.data = tab2;
    list3.data = tab3;
    
    list1.next = &list2;
    list2.next = &list3;
    ft_list_foreach(&list1, ft_print_number);
    return 0;

}