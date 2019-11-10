#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    fill_zero(char *str, size_t size)
{
    int i = -1;
    while(++i < size)
        str[i] = 0;
}

void   *brainfuck(char *str)
{
    char *ptr;
    if(!(ptr = malloc(sizeof(char) * 2048)))
        return NULL;
    fill_zero(ptr, 2048);

    while (*str)
    {
        if (*str == '>')
            ptr++;
        else if (*str == '<')
            ptr--;
        //(*ptr)++ != ptr++;
        //fais attention à la difference!!
        else if (*str == '+')
            (*ptr)++;
        else if (*str == '-')
            (*ptr)--;
        else if (*str == '.')
            write(1, ptr, 1);
        else if (*str == '[' && *ptr == 0)
        {
            while (*str != ']')
                str++;
        }
        else if (*str == ']' && *ptr != 0)
        {
            while(*str != '[')
                str--;
        }
        str++;
    }
   
}

int main(int ac, char **av)
{
    char *ptr;

    ptr = brainfuck(av[1]);
    return 0;
}