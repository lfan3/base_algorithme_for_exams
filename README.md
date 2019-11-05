# base_algorithme_for_exams
## RPN_CALC
- Data structure : pille + linked list
- utilisation d'atoi, char *str = "10 12c", atoi(str) = 10;
- dans le fichier helper, do not need if else, un single jugement, use return directly
### schema basique à bien maitriser ----- très important
>
typedef struct  s_s
{
    int         data;
    struct s_s  *next;
}               t_t
>
simple head_node
t_t *head == NULL;

t_t *push_list(int data, t_t *head)
{
    t_t *new_head;
    if (!new_head = malloc(sizeof(t_t)))
        return NULL;
    new_head->data = data;
    new_head->next = head;
    return (new_head);
}
or
t_t *push_list(int data, t_t *head)
{
    t_t *tmp;
    tmp = head;
    if (!head = malloc(sizeof(t_t)))
        return NULL;
    head->data = data;
    head->next = tmp;
    return (new_head);
}

