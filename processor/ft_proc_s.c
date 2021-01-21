/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:39 by taegor            #+#    #+#             */
/*   Updated: 2021/01/21 14:25:37 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 		print_s(s_modif *flag)
{
	int i;

	i = 0;
	if (flag->precision > 0)
	{
		while (i < flag->precision && flag->variable[i])
		{
			ft_putchar(flag->variable[i++]);
		}
	}
	else
		while (i++ < ft_strlen(flag->variable))
			ft_putchar(flag->variable[i++]);
	return (i);
}
int calc_flags(s_modif *flag)
{
	if (ft_strlen(flag->variable) - flag->precision >= flag->width)
		flag->width = 0;
	if (flag->precision == -1)
		flag->precision = ft_strlen(flag->variable);
	if (flag->width > flag->precision && flag->precision > 0)
		flag->width -= flag->precision;
	return (1);
}

int ft_print_flags(s_modif *flag)
{
	if (flag->flag == 1)
	{
		flag->result += print_s(flag);
		flag->result += ft_printspace(flag->width);
	}
	else if (flag->flag == 2)
	{
		flag->result += ft_printzero(flag->width);
		flag->result += print_s(flag);
	}
	else if (flag->flag == 0)
	{
		flag->result += ft_printspace(flag->width);
		flag->result += print_s(flag);
	}
	return (1);
}

int		ft_proc_s(char *str,s_modif *flag)
{
//	printf("res_s=%d\n", *res);
	if (str == NULL)
	{
		if ((flag->variable = ft_strdup("(null)")) == NULL)
			return (-1);
		calc_flags(flag);
		ft_print_flags(flag);
	}
	else
	{
		if ((flag->variable = ft_strdup(str)) == NULL)
			return (-1);
		calc_flags(flag);
		ft_print_flags(flag);
	}
	return (1);
}
