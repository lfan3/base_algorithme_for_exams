#include<stdio.h>
#include "floyd.h"

int main()
{
    t_item *head = circle();
    int i = detector(head);
    printf("%d\n", i);
}