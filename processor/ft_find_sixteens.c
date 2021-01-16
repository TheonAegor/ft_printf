#include "../includes/ft_printf.h"

int		ft_find_sixteens(unsigned long x)
{
	unsigned i;
	
	i = 0;
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}
