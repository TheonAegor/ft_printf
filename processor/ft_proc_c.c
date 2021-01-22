/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:28 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:48:34 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_flags_zer(t_modif *flag)
{
	if (flag->flag == 1)
	{
		flag->result += print_precision(flag);
		ft_putchar(flag->variable[0]);
		flag->result += ft_printspace(flag);
	}
	else if (flag->flag == 2)
	{
		flag->result += ft_printzero(flag);
		ft_check_minus(flag);
		ft_putchar(flag->variable[0]);
	}
	else if (flag->flag == 0)
	{
		flag->result += ft_printspace(flag);
		ft_check_minus(flag);
		flag->result += print_precision(flag);
		ft_putchar(flag->variable[0]);
	}
	return (1);
}

int		ft_proc_c(int c, t_modif *flag)
{
	if ((flag->variable = ft_calloc(sizeof(char), 2)) == NULL)
		return (-1);
	flag->variable[0] = c;
	flag->variable[1] = '\0';
	flag->result++;
	if (c == '\0')
	{
		flag->width -= 1;
		ft_calc_flags(flag);
		print_flags_zer(flag);
	}
	else
	{
		ft_calc_flags(flag);
		print_flags(flag);
	}
	return (1);
}
