#include "../includes/ft_printf.h"

int		printspace(char *str, s_modif flag)
{
	int i;
	
	i = flag.width - 1;
	while (i-- > 0)
	{
		*str = ' ';
		str++;
	}
	return (1);
}

int		printnull(s_modif *flag)
{
	if (flag->width <= 1)
		flag->width = 1;
	printspace(flag->variable, *flag);
	flag->variable[flag->width - 1] = '\0';
	if ((flag->flag) == 1)
	{
		ft_putchar('\0');
		ft_putstr(flag->variable);
	}
	else
	{
		ft_putstr(flag->variable);
		ft_putchar('\0');
	}
	free(flag->variable);
	return (0);
}
