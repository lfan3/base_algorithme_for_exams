#include <unistd.h>
#include <stdio.h>
//il faut deux conditions pour dire que les crochent sont bien fermé:
//1) meme type de crocher, autant qui ouvertent que ferment
//2) le meme type de crocher :dernier ouvert => le premier ferme.

//autant meme de type de crocher ouvert et  de fermant que ouvert
int	braclose(char *str, char c, int i, int b)
{
	while (b && *(++str) && (i++))
		if (*str == c || *str == c + c % 2 + 1)
			*str == c ? ++b : --b;
	return (i);
}

int	brackets(char *str, char c)
{
	if (*str == c)
		return (1);
	else if (!*str || *str == ')' || *str == '}' || *str == ']')
		return (0);
	else if (*str == '(' || *str == '{' || *str == '[')
  {
  		// neigber and both sides.
      // premier bracket (le dernier crocher ouvert correpondant le premier croche ferme)
  		int i;
  		i = (brackets(str + 1, *str + *str % 2 + 1)
          * brackets(str + braclose(str, *str, 1, 1), c));
			printf("bra %c\n",c);
  		return (i);
	}
    
	else
		return (brackets(str + 1, c));
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
			brackets(av[i], 0) ? write(1, "OK\n", 3) : write(1, "Error\n", 6);
	else
		write(1, "\n", 1);
	return (0);
}