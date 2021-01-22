/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:45:09 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:05:06 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proc_u(unsigned int x, s_modif *flag)
{
	char	*arg;

	if ((arg = ft_itoa_unsigned(x)) == NULL)
		return (-1);
	if (x == 0 && flag->precision == 0)
		*arg = '\0';
	if (flag->precision != -1 && flag->flag == 2)
		flag->flag = 0;
	if ((flag->variable = ft_strdup(arg)) == NULL)
		return (-1);
	free(arg);
	flag->result += ft_strlen(flag->variable);
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
