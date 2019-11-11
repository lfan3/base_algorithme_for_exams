#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void rostring(char *str)
{
    char    *ptr = str;
    int     rest_detector;
    
    //skipp the firstword
    while(*str == 32 || *str == 9)
        str++;
    while(*str != 32 && *str != 9 && *str)
        str++;

    //write the rest of the sentence
    while(*str)
    {
        while(*str == 32 || *str == 9)
            str++; 
        while(*str != 32 && *str != 9 && *str)
        {
            write(1,str, 1);
            rest_detector++;
            str++;
        }
        while(*str == 32 || *str == 9)
            str++;
        if(*str)
            write(1, " ", 1);
    }

    //write the first world
    while(*ptr == 32 || *ptr == 9)
        ptr++;
    if(rest_detector)
        write(1, " ", 1);
    while(*ptr != 32 && *ptr != 9 && *ptr)
    {
        write(1, ptr, 1);
        ptr++;
    }
    write(1, "\n", 1);
}

int main(int ac, char **av)
{
    if(ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    rostring(av[1]);
}