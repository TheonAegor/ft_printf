/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:38:39 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:11:54 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			print_s(t_modif *flag, int len)
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
		while (i < len)
		{
			ft_putchar(flag->variable[i++]);
		}
	return (i);
}

int			ft_print_flags_s(t_modif *flag, int len)
{
	if (flag->flag == 1)
	{
		flag->result += print_s(flag, len);
		flag->result += ft_printspace(flag);
	}
	else if (flag->flag == 2)
	{
		flag->result += ft_printzero(flag);
		flag->result += print_s(flag, len);
	}
	else if (flag->flag == 0)
	{
		flag->result += ft_printspace(flag);
		flag->result += print_s(flag, len);
	}
	return (1);
}

int			calc_flags_s(t_modif *flag)
{
	int len;

	len = ft_strlen(flag->variable);
	if (flag->precision >= len)
		flag->precision = len;
	else if (flag->precision == -1)
		flag->precision = len;
	else if (flag->precision < len)
		len = flag->precision;
	if (flag->width > len)
		flag->width -= len;
	else if (flag->width <= len)
		flag->width = 0;
	ft_print_flags_s(flag, len);
	return (1);
}

int			ft_proc_s(char *str, t_modif *flag)
{
	if (str == NULL)
	{
		if ((flag->variable = ft_strdup("(null)")) == NULL)
			return (-1);
		calc_flags_s(flag);
	}
	else
	{
		if ((flag->variable = ft_strdup(str)) == NULL)
			return (-1);
		calc_flags_s(flag);
	}
	return (1);
}
