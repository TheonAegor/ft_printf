/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:47 by taegor            #+#    #+#             */
/*   Updated: 2021/01/21 18:58:24 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int len;

	len = ft_strlen(flag->variable);
	len -= ft_check_minus(flag);
//    printf("precision=%d\n", flag->precision);
//    printf("width=%d\n", flag->width);
	if (flag->type == 'c')
		flag->precision = 0;
    if (len >= flag->width)
        flag->width = 0;
    if (len >= flag->precision)
        flag->precision = 0;
    if (flag->precision >= flag->width)
        flag->width = 0;
    if (flag->width > len)
        flag->width = flag->width - len;
    if (flag->precision > len)
        flag->precision -= len;
	flag->width -= flag->precision;
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

int 	ft_print_prec_less_neg(s_modif *flag)
{
	char *tmp;
	int len;

	len = ft_strlen(flag->variable);
	if (*flag->variable == '-')
		len -= 1;
	if (len < flag->precision)
	{
		flag->result += ft_putchar('-');
        flag->result += print_precision(flag->precision - 1);
		tmp = flag->variable;
		flag->variable = ft_strdup(&flag->variable[1]);
		free(tmp);
	}
	return (1);
}

int print_flags(s_modif *flag)
{
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
		if (*flag->variable  == '-')
			ft_print_prec_less_neg(flag);
		else
        	flag->result += ft_printspace(flag->width);
        flag->result += print_precision(flag->precision);
        ft_putstr(flag->variable);
    }
    return (1);
}
