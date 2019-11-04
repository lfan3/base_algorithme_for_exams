#include <unistd.h>
#include <stdio.h>
#include "biggest_pal.h"

int get_len(char *str)
{
    int i = 0;
    
    while(str[i])
        i++;
    return i;
}

// pour voir

void affichier_tab(int tab[N][N])
{
    int i = 0;
    int j = 0;
    int n = N;

    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            printf("%d ", tab[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void affichier_pal(char *str, int start, int end)
{
    while (start <= end)
    {
        write(1, &str[start], 1);
        start++;      
    }
        write(1, "\n", 1);
}

void biggest_pal(char *str)
{
    int i=0;
    int j=0;
    int k=2;
    int maxL=0;
    int start=0;
    int end=0;
    int n=0;    // voir si n sera vraiment utile. sinon re,place len par n

    n = get_len(str);
    
    // remplire le tab with 0
    int tab[n][n];
    while (i < n)
    {
        j = 0;
        while (j < n)
        {
            tab[i][j] = 0;
            j++;
        }
        i++;
    }
    affichier_tab(tab);

    //begining of algo == begin to fille the sub_string table
    //sub_strint with only one letter
    maxL=1;
    i = -1;
    while (++i < n)
        tab[i][i] = 1;
    //sub_string with two letters
    i = -1;
    while (++i < n - 1)
    {
        if (str[i]==str[i + 1])
        {
           tab[i][i+1]=1;
           maxL = 2;
        }
    }
    //sub_string with >= 3 letters
    while (++k < n)
    {
        i = -1;
        while (++i < n - k)
        {
            j = i + k - 2;
            while(++j < n)
            {
                if(tab[i+1][j-1] == 1 && str[i] == str[j])
                {
                    tab[i][j] = 1;
                    if (j - i + 1 > maxL)
                    {
                        start = i;
                        end = j;
                        maxL = j - i + 1;
                    }
                }
            }
        }
    }
    affichier_pal(str, start, end);
    printf("%d\n", maxL);
    affichier_tab(tab);
    
}

    