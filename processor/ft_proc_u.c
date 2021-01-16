#include "../includes/ft_printf.h"

int		ft_proc_u(unsigned long x, int *res, s_modif *flag)
{
	int category;
	int	tmp;

	category = ft_find_tens(x);
	printf("category=%d\n", category);
	flag->variable = ft_calloc(sizeof(char), 2);	
	flag->variable[category--] = '\0';
	while(category >= 0)
	{
		tmp = x % 10;
		printf("%d\n", tmp);
		flag->variable[category--] = tmp + 48; 
		x = x / 10;
		++*res;
	}
	return (1);
}
