#include <stdlib.h>
#include <stdio.h>

//ht_create()
//ht_put()
//ht_get()
//ht_free()

typedef struct s_list
{
    char *key;
    char *value;
    struct s_list *next;
}               t_list;

typedef struct s_hash_table
{
    unsigned int size;
    t_list      **array; //??
}              t_hash_table;

t_hash_table *ht_create(unsigned int size)
{
    t_hash_table *ht;

    if (size < 1)
        return NULL;
    ht = malloc(sizeof(t_hash_table));
    if(ht == NULL)
        return NULL;
    ht->array = (t_list**)malloc(size * sizeof(t_ist)); //? *t_list
    if (ht->array == NULL)
        return (NULL);
    memset(ht->array, 0, size * sizeof(t-t_list));
    ht->size = size;
    return ht;
}

unsigned int hash(const char *key, unsigned int size)
{
    unsigned int hash;
    unsigned int i;

    hash = 0;
    i = 0;
    while(key && key[i])
    {
        hash = (hash + key[i]) % size;
        ++i;
    }
    return (hash);
}

int ht_put(t_hash_table *hashtable, const char *key, const char *value)
{
    t_list *node;

    if(hashtable == NULL)
        return 1;
    node = malloc(sizeof(t_list));
    if(node == NULL)
        return 1;
    node->key = strdup(key);
    node->value = strdup(value);

    node_handler(hashtable,node);
    return 0;
}

void node_handler(t_hash_table *hashtable, t_list *node)
{
    unsigned int i = hash(node->key, hashtable->size);
    t_list *tmp = hashtable->array[i];
    if(hashtable->array)
}
int main()
{
    t_hash_table *ht;

    ht = ht_create(1);
    if(ht==NULL)
        return NULL;
    if(ht_put(ht, "isFun", "c") == 0)
    {
        printf("%s\n", ht_get(ht, "isFun"));
        ht_free(ht);
        return 0;
    }
    return 1;
}