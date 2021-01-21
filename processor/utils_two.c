#include "../includes/ft_printf.h"

int 	ft_check_minus(s_modif *flag)
{
	char *tmp;

	if (*flag->variable == '-')
	{
		ft_putchar('-');
		tmp = flag->variable;	
		flag->variable = ft_strdup(&flag->variable[1]);
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_calc_flags_two(s_modif *flag)	
{
	return (1);
}
