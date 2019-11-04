#include <unistd.h>
#include <stdio.h>

#define BUFF 2408

int bracket(char *str)
{
    int i = 0;
    char pile[BUFF] = {0};
    
    while (*str)
    {
        if (*str== '{' || *str== '[' || *str == '(')
            pile[++i] = *str;
        else if (*str== '}' || *str== ']' || *str == ')')
        {
            if (pile[i]+pile[i]%2+1== *str)
                i--;
            else
                return (0);
        }
        str++;          
    }
    if (i == 0)
        return 1;
    return (0);
}

int main(int ac, char **av)
{
    int i = 1;
    if (ac <= 1)
    {
        write(1,"\n", 1);
        return 0;
    }

    while (i < ac)
    {
        bracket(av[i]) ? write(1,"ok\n",3) : write(1, "error\n", 6); 
        i++;
    }
    return 0;     
}