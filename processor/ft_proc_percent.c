#include "../includes/ft_printf.h"

int 	ft_proc_percent(s_modif *flag)
{
	if ((flag->variable = ft_calloc(sizeof(char), 2)) == NULL)
			return (-1);
	flag->variable[0] = '%';
	flag->variable[1] = '\0';
	flag->result++;
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
