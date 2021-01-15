#include "../includes/ft_printf.h"

void	ft_print_hex(int x);
	
int		ft_processor(s_modif *flag, va_list args)
{
	int		p;

	if (flag->type == 'd' || flag->type == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (flag->type == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), 1);
	if (flag->type == 'c')
		ft_putchar(va_arg(args, int));
	if (flag->type == 's')
		ft_putstr(va_arg(args, char*));
	if (flag->type == 'x' || flag->type == 'X')
		ft_print_hex(va_arg(args, int));
	if (flag->type == 'p')
		;
	return (1);
}

void	ft_print_hex(int x)
{
	if (x >= 16)
	{
		ft_print_hex(x/16);
		ft_print_hex(x%16);
	}
	if (x < 10)
	{
		ft_putchar(x^48);
		return ;
	}
	if (x >= 10 && x <= 15)
	{
		ft_putchar(((x + 1) % 10) | 48 ^ 80 );
		return ;
	}
}
