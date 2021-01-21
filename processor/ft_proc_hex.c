#include "../includes/ft_printf.h"

int		ft_proc_hex(unsigned long x, s_modif *flag)
{
	long long int	category;
	unsigned long int			tmp;

	category = ft_find_sixteens(x);
	if ((flag->variable = ft_calloc(sizeof(char), category + 1)) == NULL)
		return (-1);
	flag->variable[category--] = '\0';
	while (category >= 0 )
	{
		tmp = x % 16;
		if (tmp < 10)
			flag->variable[category--] = tmp + 48; 
		if (tmp >= 10 && tmp <= 15 && flag->type == 'x')
			flag->variable[category--] = (((tmp + 1) % 10) | 48) ^ 80; 
		else if (tmp >= 10 && tmp <= 15 && flag->type == 'X')
			flag->variable[category--] = (((tmp + 1) % 10) | 48) ^ 112; 
		flag->result++;	
		x = x / 16;
	}
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
