#include "../includes/ft_printf.h"

int		ft_proc_s(char *str, int *res,s_modif *flag)
{
	flag->variable = ft_strdup(str);
	*res = *res + ft_strlen(str);
	return (1);
}
