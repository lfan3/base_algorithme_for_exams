#include <stdio.h>

int barclose(char *str, char c, int i, int b)
{
    while(b && *(str++) && (i++))
        if (*str == c || *str == c + c % 2 + 1)
            *str == c ? ++b : --b;
    return (i);
}

int brackets(char *str, char c)
{
    if (*str == c)
        return 1;
    else if (!*str || *str == ']' || *str == ')' || *str == '}' )
        return 0;
    else if (*str == '(' || *str == '[' *str == '{')
        return (brackets(str++, (*str + *str % 2 + 1)));
    else 
        return brackets(str+1, c);
}
int main()
{
    char *str = "5+(4)*7-1";
    printf("%d\n", braclose(str + 2, '(', 1, 1));
    return 0;
}