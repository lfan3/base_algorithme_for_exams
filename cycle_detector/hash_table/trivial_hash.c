#include <stdio.h>

#define MAX 10

int array[MAX+1][2];

//search if X is presented 
int search(int x)
{
    if(x >=0)
    {
        if(array[x][0] == 1)
            return 1;
        else
            return 0;
    }
    if(array[-x][1] == 1)
        return 1;
    return 0;
}
// an array of -MAX to MAX
void insert(int arr[], int  size)
{
    int i = 0;
    while (i < size)
    {
        if (arr[i] >= 0)
            array[arr[i]][0] = 1;
        else
            array[-arr[i]][1] = 1;
        i++;
    }
}

int main()
{
    int a[] = {-1, 2, 3, -4};
    int size = sizeof(a) / sizeof(a[0]);
    insert(a, size);
    int x = 3;
    int y = 6;
    if (search(x))
    {
        printf("present\n");
    }
    else
        printf("not present\n");

    if (search(y))
    {
        printf("present\n");
    }
    else
    printf("not present\n");
    return 0;
}