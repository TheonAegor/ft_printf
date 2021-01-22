/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:45:00 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:32:28 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_calc_flags_d_neg(s_modif *flag)
{
	int len;

	len = ft_strlen(flag->variable) - 1;
	if (len >= flag->precision)
		flag->precision = 0;
	if (len + 1 >= flag->width)
		flag->width = 0;
	if (flag->precision > len)
		flag->precision -= len;
	if (flag->width > len + 1)
		flag->width -= len + 1;
	if (flag->width > flag->precision && flag->precision >= 0)
		flag->width -= flag->precision;
	else if (flag->precision >= flag->width)
		flag->width = 0;
	return (1);
}

int		ft_proc_d(int x, s_modif *flag)
{
	char *arg;

	if ((arg = ft_itoa(x)) == NULL)
		return (-1);
	if (x == 0 && flag->precision == 0)
		*arg = '\0';
	if ((flag->variable = ft_strdup(arg)) == NULL)
		return (-1);
	free(arg);
	flag->result += ft_strlen(flag->variable);
	if (flag->precision != -1 && flag->flag == 2)
		flag->flag = 0;
	if (*flag->variable == '-')
	{
		ft_calc_flags_d_neg(flag);
		ft_check_minus(flag);
	}
	else
		ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
