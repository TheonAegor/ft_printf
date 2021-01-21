#include "../includes/ft_printf.h"

int 	ft_printspace(int count)
{
	int i;

	i = 0;
	while (count-- > 0)
	{	
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int 	ft_printzero(int count)
{
	int i;

	i = 0;
	while(count-- > 0)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

int        ft_calc_flags(s_modif *flag)
{
    if (ft_strlen(flag->variable) >= flag->width)
        flag->width = 0;
    if (ft_strlen(flag->variable) >= flag->precision)
        flag->precision = 0;
    if (flag->precision >= flag->width)
        flag->width = 0;
    else if (flag->width > flag->precision)
        flag->width = flag->width - flag->precision;
    if (flag->precision > ft_strlen(flag->variable))
        flag->precision -= ft_strlen(flag->variable);
/*
    printf("flag=%d\n", flag->flag);
    printf("width=%d\n", flag->width);
    printf("precision=%d\n", flag->precision);
    printf("var=%s\n", flag->variable);
*/
    return (1);
}

int print_precision(int count)
{
    int i;

    i = 0;
    while(count-- > 0)
    {
        ft_putchar('0');
        i++;
    }
    return (i);
}

int print_flags(s_modif *flag)
{
	if (flag->precision != 0)
		flag->precision += ft_check_minus(flag);
	else
		ft_check_minus(flag);
    if (flag->flag == 1)
    {
        flag->result += print_precision(flag->precision);
        ft_putstr(flag->variable);
        flag->result += ft_printspace(flag->width);
    }
    else if (flag->flag == 2)
    {
        flag->result += print_precision(flag->precision);
        flag->result += ft_printzero(flag->width);
        ft_putstr(flag->variable);
    }
    else if (flag->flag == 0)
    {
        flag->result += print_precision(flag->precision);
        flag->result += ft_printspace(flag->width);
        ft_putstr(flag->variable);
    }
    return (1);
}
