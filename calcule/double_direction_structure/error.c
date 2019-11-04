#include "calculate.h"

int no_other_char(char *str)
{
    while (*str)
    {
        if ((*str >= '0' && *str <= '9') || *str == '+' \
            || *str == '-' || *str == '*' || *str == '/' \
            || *str == '%' || *str == ' ')
            str++;
        else
            return 0;
    }
    return (1);
}

int right_nb_opera(char *str)
{
    int i = 0;
    int b = 0;
    while (*str)
    {
        if (*str == '+' || *str == '-' || *str == '*' \
        || *str == '/' || *str == '%')
            i++;
        else if (*str == ' ')
            b++;
        str++;
    }
    if (b == 2 * i)
        return (1);
    return (0);
}

int    sign_at_right_position(char *str)
{
    int i = -1;
    
    if (str[0] == '+' || str[0] == '-' || str[0]== '*' \
        || str[0] == '/' || str[0] == '%')
        return (0);
    while (str[i+1])
        i++;
    if (str[i] != '+' && str[i] != '-' && str[i] != '*'\
        && str[i] != '/' && str[i] != '%')
        return (0);
    return (1);
}

//first two number!
int no_error(char *str)
{
    if (no_other_char(str) && sign_at_right_position(str) \
        && right_nb_opera(str))
        return (1);
    return (0);
}
