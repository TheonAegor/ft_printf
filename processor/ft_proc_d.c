#include "../includes/ft_printf.h"



int		ft_proc_d(int x, s_modif *flag)
{
	char *arg;

	if ((arg = ft_itoa(x)) == NULL)
		return (-1);
	if (x == 0 && flag->precision == 0)
		*arg = '\0';
	if ((flag->variable = ft_strdup(arg)) == NULL)
		return (-1);
	flag->result += ft_strlen(flag->variable);
	if (flag->precision != -1 && flag->flag == 2)
		flag->flag = 0;
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
