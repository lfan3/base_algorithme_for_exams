#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i = 0;
    int a;

    (void)ac;
    while (av[1][i])
    {
        while (av[1][i] && av[1][i] == 32)
            i++;
        if (av[1][i] >= '0' && av[1][i] <= '9')
            a= atoi(&av[1][i]);
            printf("%d\n", a);
        while(av[1][i] >= '0' && av[1][i] <= '9')
            i++;
  

    }
    return 0;

}