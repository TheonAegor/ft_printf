/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:47 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:44:43 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 	ft_printspace(s_modif *flag)
{
	int i;

	i = 0;
	if (flag->width <= 0)
		return (0);
	while (flag->width-- > 0)
	{	
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int 	ft_printzero(s_modif *flag)
{
	int i;

	i = 0;
	if (flag->width <= 0)
		return (0);
	while(flag->width-- > 0)
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
 	if (flag->type == 'c' && flag->precision != -1)
		flag->precision = 0;
    if (len >= flag->precision && flag->precision != -1)
        flag->precision = 0;
    if (len >= flag->width)
        flag->width = 0;
    if (flag->precision > len)
        flag->precision -= len;
    if (flag->width > len)
        flag->width = flag->width - len;
	if (flag->width > flag->precision && flag->precision >= 0)
		flag->width -= flag->precision;
    else if (flag->precision >= flag->width)
        flag->width = 0;
    return (1);
}

int print_precision(s_modif *flag)
{
    int i;

    i = 0;
	if (flag->precision <= 0)
		return (0);
    while(flag->precision-- > 0)
    {
        ft_putchar('0');
        i++;
    }
    return (i);
}
/*
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
*/

int print_flags(s_modif *flag)
{
    if (flag->flag == 1)
    {
        flag->result += print_precision(flag);
        ft_putstr(flag->variable);
        flag->result += ft_printspace(flag);
    }
    else if (flag->flag == 2)
    {
//        flag->result += print_precision(flag->precision);
        flag->result += ft_printzero(flag);
		ft_check_minus(flag);
        ft_putstr(flag->variable);
    }
    else if (flag->flag == 0)
    {
/*
 		printf("width=%d\n", flag->width);
		if (*flag->variable  == '-')
			ft_print_prec_less_neg(flag);
		else
        	flag->result += ft_printspace(flag->width);
*/
        flag->result += ft_printspace(flag);
		ft_check_minus(flag);
        flag->result += print_precision(flag);
        ft_putstr(flag->variable);
    }
    return (1);
}
