#include "../includes/ft_printf.h"

int		ft_copysrc(char *dst, char *src)
{
	int i;

	i = 0;
	if (src == NULL)
	{
		dst[i] = '\0';
		return (0);
	}
	if (dst == NULL)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst));
}
