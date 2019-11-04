#include <stdlib.h>
#include <stdio.h>

char *new()
{
    char *s;
    s= malloc(sizeof(char) * 10);
    s = "nice";
    return s;
}
int main()
{
    char *s;
    s = new();
    printf("%s\n", s);
    s = NULL;

  
}