#include<stdio.h>
#include "floyd.h"

int main()
{
    // this is pille_circle creation main part
    int tab[5] = {1, 2, 3, 4, 5};
    int len = 5;
    t_item *head = NULL;
    t_item *tete = NULL;
    head = circle_creator(head, tab, len);   
    tete = create_lineral_liste(tete, tab, len);
    int re = circle_detector(head);
    int rt = circle_detector(tete);

    printf("%d\n", re);
    printf("%d\n", rt);
    return 0;
}