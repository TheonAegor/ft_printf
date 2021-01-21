#include "../includes/ft_printf.h"

char	*ft_itoa_unsigned(unsigned long x)
{
	char			*res;	
	unsigned int	i;
	int				category;

	category = ft_find_tens(x);
	if ((res = ft_calloc(sizeof(char), category + 1)) == NULL)
		return (NULL);
	res[category--] = '\0';
	if (x == 0)
		res[0] = '0';
	while (x > 0)
	{
		res[category--] = x % 10 + 48;
		x = x / 10;
	}
	return (res);
}
