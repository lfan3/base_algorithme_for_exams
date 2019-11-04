#include <stdio.h>
#define SIZE = 10

typedef struct  s_s
{
    int key;
    int data;
    struct s_s **array;  
}               t_s;

int index(int key, t_s *ele, int size)
{
    int hash = key % size;
    return hash;
}

t_s creat(int size)
{
    t_s *ht;

    ht = malloc(sizeof(t_s));
    ht->array = malloc(sizeof(t_s *) * size);
    return t_s;
}