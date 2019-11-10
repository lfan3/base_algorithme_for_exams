#include <stdio.h>
#include <stdlib.h>

void    fill_zero(int *str, size_t size)
{
    int i = -1;
    while(++i < size)
        str[i] = 0;
}

int main()
{
    int *ptr;
    if(!(ptr = malloc(sizeof(int) * 2048)))
        return 0;
    fill_zero(ptr, 2048);
    printf("%d", ptr[0]);
    printf("%d", ptr[1]);

    (*ptr)++; //(*ptr)++ != *ptr++
    printf("%d", ptr[0]);
    printf("%d", ptr[1]);


}