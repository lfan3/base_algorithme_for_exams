//seperate the string in double string,
//atoi the number
//make operation
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

char **big_cases(char *str, int len)
{
    char **outer;
    int i=0;
    int k = 0;
    int n = 0;

    if (!(outer = (char **)malloc(sizeof(char *) * len)))
        return NULL;
    while (i < len)
    {
        if (str[n])
            outer[i] = small_case(str + k);
        while (str[n] != ' ' && str[n])
            n++;
        n++;
        k = n;
        i++;        
    }
    return (outer);
}

t_list  list_init(char *str, int size)
{
    t_list *begin;
    t_list *lst;
    int i = 0;
    int n = 0;
    int k = 0;

    if(!(begin = malloc(sizeof(t_list))))
        return NULL;
    lst = begin;
    while (i < size)
    {
        if (str[n])
        {
            begin->str = small_case(str + k);
            if (str(n + 1))
                begin->next 
        }
    }

}

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

int     calculate(char **str, int nb)
{
    int i = 0;
    int tmp;
    int result;

    while(str[i])
    {
         if (compa_str(str[i], "+")

         
         && (compa_str(str[i], "-") \
            && (compa_str(str[i], "*") \
            && (compa_str(str[i], "/") && (compa_str(str[i], "%"))
    }
}

int main(int ac, char **av)
{
    int i = -1;
    int c;
    int b;
    char **str;

    if (ac != 2)
        printf("\n");
    c = no_error(av[1]);
    if (c == 1)
        b = nb_cases(av[1]);
    str = big_cases(av[1], b);
    while (++i < b)
    {
        if ((!compa_str(str[i], "+") && (!compa_str(str[i], "-") \
            (!compa_str(str[i], " ") && (!compa_str(str[i], "*") \
            (!compa_str(str[i], "/") && (!compa_str(str[i], "%"))
            printf("%d\n", atoi(str[i]));
    }
    int comp = compa_str("abc", "abcd");
    printf("com %d\n", comp);
        printf("%d\n", atoi(str[1]) * atoi(str[0]));  
    return 0;


    return 0;
}
