#include "pcal.h"

int is_espace(char c)
{
    return( c == 32);
}

int is_digit(char c)
{
    return ('0'<= c && c <= '9');
}

int is_operater(char c)
{
    return (c == '+' || c == '-' \
            || c == '*' || c == '/' || c == '%');
}