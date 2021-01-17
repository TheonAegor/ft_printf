#include "../includes/ft_printf.h"

static int	fill_var(int *category, s_modif *flag, long long int x, int *res)
{
	int	tmp;

	if (*category > 0)
		--*res;
	while(*category >= 0)
	{
		tmp = x % 10;
		flag->variable[*category] = tmp + 48; 
		*category = *category - 1;
		x = x / 10;
		++*res;
		flag->result++;
	}
	return (1);
}

int		ft_proc_d(int x, int *res, s_modif *flag)
{
	int category;

	if (x == -2147483648)
	{
		flag->variable = ft_calloc(sizeof(char), category + 1);	
		ft_copysrc(flag->variable, "-2147483648");
		flag->result += ft_strlen(flag->variable);
	}
	else if (x < 0)
	{
		x = (unsigned)x * (-1);
		category = ft_find_tens(x) + 1;
		flag->variable = ft_calloc(sizeof(char), category + 1);	
		flag->variable[category--] = '\0';
		fill_var(&category,flag, x, res);
		flag->variable[0] = '-';
	}
	else
	{
		category = ft_find_tens(x);
		flag->variable = ft_calloc(sizeof(char), category);	
		flag->variable[category--] = '\0';
		fill_var(&category,flag, x, res);
	}
	return (1);
}
