#include <stdio.h>
#include <unistd.h>

int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};

void print_number(int numb)
{
    char frist_num;
    char second_num;
    int fn;
    int sn;
    int i = 0;

    fn= numb / 16;
    sn = numb % 16;
    if(fn < 10)
        frist_num = fn + '0';
    else
        frist_num = fn - 10 + 'a';
    if (sn < 10)
        second_num = sn + '0';
    else
        second_num = sn - 10 + 'a';
    write(1, &frist_num, 1);
    write(1, &second_num, 1);
    while (i < 7)
    {
        if (i != 2)
            write(1,"0", 1);
        else
            write(1, " ", 1);
        i++;
    }
}

void afficher_le_sign(int nb)
{
    if (nb > 33 && nb < 125)
    {
        write(1, &nb, 1);
        write(1, ".", 1);    
    }
    else
    {
        write(1, ".", 1);    
        write(1, ".", 1);
    }
    write(1, ".", 1);
    write(1, ".", 1);    
}
//consider the last line, nb_num = the number of last line numbers
void print_sign_tab(int *tab, int nb_num)
{
    int i = 0;
    while(i < nb_num)
    {
        afficher_le_sign(tab[i]);       
        i++;
    }
    write(1, "\n", 1);
}

void print_tab(int *tab, int tab_size)
{
    int i = 0;
    int tmp_counter;
    int nb_num = 0;
    int k = 0;
    while(i < tab_size)
    {
        if (i > 3 && ! (i % 4))
        {
            tmp_counter = i;
            print_sign_tab(&tab[tmp_counter-4], 4);
        }
        print_number(tab[i]); 
        //last line              
        if (i == (tab_size-1))
        {
            nb_num = tmp_counter + 3 - i; 
            while(k < (nb_num * 9 + 3))
            {
                write(1, " ", 1);
                k++;
            }
           print_sign_tab(&tab[tmp_counter], nb_num);
        }
        write(1, " ", 1);
        i++;
    }
}

int main()
{
    print_tab(tab,10);
    return 0;
}

