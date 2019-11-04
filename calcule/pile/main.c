#include <stdio.h>
#include "pcal.h"

int main(int ac, char **av)
{
    t_t *resu;

    if (ac != 2)
    {
        printf("\n");
        return 0;
    }
    resu = read(av[1]);
    printf("%d\n", resu->data);
    return 0;
}
