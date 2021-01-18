#include "../includes/ft_printf.h"

int		ft_proc_c(int c, int *res,s_modif *flag)
{
	if(!(flag->variable = ft_calloc(sizeof(char), flag->width + 1)))
		return (-1);
	if (c == '\0')
	{
		if (printnull(*flag) == -1)
			return (-1);	
		return (flag->width);
	}
	if (flag->width <= 1)
		flag->width = 1;
	flag->variable[0] = c; 
	if (flag->flag == 1)
		printspace(&flag->variable[1], *flag);
	else
	{
		ft_memmove(&flag->variable[flag->width - 1], flag->variable, 1); 
		printspace(flag->variable, *flag);
	}
	flag->variable[flag->width] = '\0'; 
	ft_putstr(flag->variable);
	flag->result++;
	return (1);
}
