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
// compare the two mains, we can find out that the first code is much cleaner!
int main(int ac, char **av)
{
    int i = 1;
    if (ac <= 1)
    {
        write(1,"\n", 1);
        return 0; //not forget
    }

    while (i < ac) // not to use av[i], sometimes there is problems
    {
        bracket(av[i]) ? write(1,"ok\n",3) : write(1, "error\n", 6); //simple if
        i++;
    }
    return 0;     
}

int main(int ac, char **av)
{
    int i = 1;
    int k = 1;
    if(ac == 1)
        write(1,"\n",1);
    else
    {
        while (av[i])
        {
            k =  bracket(av[i]);
            if(k == 0)
                write(1,"Error\n", 6);
            else
                write(1, "OK\n", 3);
            i++;
        }

    }
    return 0;
}