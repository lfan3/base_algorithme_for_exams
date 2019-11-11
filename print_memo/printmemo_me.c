#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_hex(int nu)
{
    char c;
    if(nu < 16)
    {
        nu < 10 ? ft_putchar(nu + '0') : ft_putchar(nu + 'a' - 10);
        return;
    }
    print_hex(nu/16);
    c = nu%16 + (nu%16<10 ? '0' : 'a'-10);
    ft_putchar(c);
}
//seconde way to write the same recursive fonction
void print_hex_2(int nu)
{
    if(nu >= 16)
        print_hex_2(nu/16);
    nu % 16 < 10 ? ft_putchar(nu%16 + '0') : ft_putchar(nu%16 + 'a' - 10);
}

void print_two_zero(void)
{
    ft_putchar('0');
    ft_putchar('0');
}

void print_each_num(int nb)
{
    if(nb < 16)
        ft_putchar('0');
    print_hex_2(nb);
    print_two_zero();
    write(1, " ", 1);
    print_two_zero();
    print_two_zero();
    write(1, " ", 1);

}

void print_sign(int nb)
{
    char c;
    c = (nb > 31 && nb < 127) ? nb : 46;
    ft_putchar(c);
    ft_putchar(46);
    ft_putchar(46);
    ft_putchar(46);
}

void print_espace(void)
{
    int i = -1;
    while(++i < 10)
        ft_putchar(32);
}

//three variable: row_conuter, index_for_number, index_for_signe
void print_memory(const void *addr, size_t size)
{
    const int *tab;
    tab = (const int*)addr;
    size_t len = size / sizeof(int);
    int i = -1;
    int j = 0;
    int row_counter=0;

    while(++i < len)
    {
        print_each_num(tab[i]);
        //count the row
        if(((i+1)%4==0 && i != -1) || (i == len-1) )
            row_counter++;
        if((i+1)%4 == 0 && len >= 4*row_counter && i != -1)
        {
            j = i - 4;
            while(++j <= i)
                print_sign(tab[j]);
            ft_putchar('\n');
        }
        //reach the end
        if(i == len -1)
        {
            int n = 4*row_counter - len + 1;
            while(--n)
                print_espace();
            j = 4*row_counter - 5;
            while(++j < len)
                print_sign(tab[j]);
            ft_putchar('\n');
        }
    }
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}