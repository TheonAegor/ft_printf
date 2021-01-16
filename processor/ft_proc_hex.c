#include "../includes/ft_printf.h"

/*
{
	static int res;

	res = 0;
	if (x >= 16)
	{
		ft_print_hex(x/16);
		ft_print_hex(x%16);
	}
	if (x < 10)
		res += ft_putchar(x^48);
	if (x >= 10 && x <= 15)
		res += ft_putchar(((x + 1) % 10) | 48 ^ 80 );
	return res;
}
*/

int		ft_proc_hex(unsigned long x, int *res, s_modif *flag)
{
	long long int	category;
	unsigned long int			tmp;

	category = ft_find_sixteens(x);
	flag->variable = malloc(sizeof(char)* category + 1);
	flag->variable[category--] = '\0';
	while (category >= 0 )
	{
		tmp = x % 16;
		if (tmp < 10)
			flag->variable[category--] = tmp + 48; 
		if (tmp >= 10 && tmp <= 15)
			flag->variable[category--] = ((tmp + 1) % 10) | 48 ^ 80; 
		++*res;
		x = x / 16;
	}
	return (1);
}
