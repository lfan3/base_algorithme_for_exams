#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct List
{
    char *key;
    int value;
    struct List *next;
}               List;

typedef struct HashTable
{
    unsigned int size;
    List **array;
}               HashTable;

int hash(char *key, unsigned int size)
{
    int hash = 0;
    while(*key)
    {
        hash = (hash + *key); //how to garentee the table size is enought?
        key++;
    }
    hash = hash % size;
    return (hash);
}

HashTable *ht_create(unsigned int size)
{
    HashTable *ht;

    if(!(ht = malloc(sizeof(HashTable))))
        return NULL;
    if(!(ht->array = malloc(sizeof(List *) * size)))
        return NULL;
    ht->size = size;
    return (ht);
}

void ft_put(HashTable *Ht, char *key, int value)
{
    List *node;
    List *tmp;
    int index;

    node = malloc(sizeof(List));
    tmp = malloc(sizeof(List));
    node->key = strdup(key);
    node->value = value;
    index = hash(key,Ht->size);
    tmp = Ht->array[index];
    
    if(!tmp)
    {
        Ht->array[index] = node; 
        node->next = NULL;
    }
    else
    {
        while(Ht->array[index])
        {
            if(strcmp(key, Ht->array[index]->key))
                index++;
        }
        if(!(Ht->array[index]))
        {
            Ht->array[index] = node;
            node->next = NULL;
        }



    }
 
}

int search(HashTable *ht, char *key)
{
    int index;
    index = hash(key,ht->size);
    return()
}

int main()
{
    HashTable *HT;
    
    HT = ht_create(100);
    ft_put(HT,"abc", 130);
    int index = hash("abc", 100);

    printf("%d\n",HT->array[index]->value);
   

}
