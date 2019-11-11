#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
//important
void print_hex(unsigned int nu)
{
    char c;

    if(nu >= 16)
        print_hex(nu/16);
    c = nu % 16 + (nu%16<10 ? '0' : 'a'-10);
    ft_putchar(c);    
}

void print_un_numb(unsigned int c)
{
    if (c < 16)
        ft_putchar('0');
    print_hex(c);
    ft_putchar('0');
    ft_putchar('0');

    ft_putchar(32);

    ft_putchar('0');
    ft_putchar('0');
    ft_putchar('0');
    ft_putchar('0');
    ft_putchar(32);

}

void   ft_printchars(unsigned int c)
{
    ft_putchar((c>31 && c<127)? 'c' : '.');
    ft_putchar('.');
    ft_putchar('.');
    ft_putchar('.');
}


void    print_memory(const void *addr, size_t size)
{
    //important
    unsigned int *t = (unsigned int*)addr;
    int len = size / 4;
    int i = 0;
    int j = 0;
    int row = 0;
    while(i < len)
    {
        if (!(i%4) && i!=0)
        {
            j = i-4;
            while (j < i)
            {
                ft_printchars(t[j]);
                j++;
            }
            ft_putchar('\n');
            row ++;
        }
        print_un_numb(t[i]);
        i++;
    }
    while(i>=len && i < (row+1) * 4)
    {
        
    }

}

int main()
{
   	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}