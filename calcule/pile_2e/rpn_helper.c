#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rpn_calc.h"

int is_space(char c)
{
    return (c == 32);
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_operator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int calculate(int a, int b, char c)
{
    int resulte;

    if (c=='*')
        resulte = a * b;
    else if (c=='+')
        resulte = a + b;
    else if (c == '-')
        resulte = a - b;
    else if (c =='/')
        resulte = a / b;
    return (resulte);
}