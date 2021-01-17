#include "../includes/ft_printf.h"

int		ft_proc_s(char *str, int *res,s_modif *flag)
{
//	printf("res_s=%d\n", *res);
	flag->variable = ft_strdup(str);
	flag->result += ft_strlen(str);
	return (1);
}
