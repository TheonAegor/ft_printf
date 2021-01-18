#include "../includes/ft_printf.h"

int		ft_print_hex(unsigned x, int *res);
	
int		ft_processor(s_modif *flag, va_list args, int *res)
{
	int change;
	
	change = *res;
//	printf("res_b%d\n", *res);
	if (flag->type == 'd' || flag->type == 'i')
		ft_proc_d(va_arg(args, int), res, flag);
	if (flag->type == 'u')
		ft_proc_u(va_arg(args, unsigned long int), res, flag);
	if (flag->type == 'c')
		flag->result += ft_proc_c(va_arg(args, int), res, flag);
	if (flag->type == 's')
		ft_proc_s(va_arg(args, char*), res, flag);
	if (flag->type == 'x' || flag->type == 'X')
		ft_proc_hex(va_arg(args, long unsigned), res, flag);
	if (flag->type == 'p')
		ft_proc_p(va_arg(args, unsigned long int), res, flag);
/*	
 	printf("var=%s\n", flag->variable);
	printf("in_proc%d\n", *res);
	if (*res != change)
		*res = *res - (*res - change);
	printf("res_proc=%d\n", flag->result);
	printf("res_b%d\n", *res);
	printf("change=%d\n", change);
*/
	return (*res);
}
/*
int		ft_print_hex(unsigned x, int *res)
{
//	x < 0 ? x = (unsigned)x * (1) : (x = (unsigned)x);
	if (x >= 16)
	{
		ft_print_hex(x/16, res);
		ft_print_hex(x%16, res);
	}
	if (x < 10)
		*res += ft_putchar(x^48);
	if (x >= 10 && x <= 15)
		*res += ft_putchar(((x + 1) % 10) | 48 ^ 80 );
	return *res;
}
*/
