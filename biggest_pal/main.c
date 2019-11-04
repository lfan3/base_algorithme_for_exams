#include <stdio.h>
#include <unistd.h>
#include "biggest_pal.h"

int main(int ac, char **av)
{
    if (ac != 2)
        write (1, "\n", 1);
    else
       biggest_pal_obb_even(av[1]); 
    return 0;
}
