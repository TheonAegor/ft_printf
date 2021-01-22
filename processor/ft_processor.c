/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:47:39 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:34:31 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_processor(t_modif *flag, va_list args, int *res)
{
	int result;

	if (flag->type == 'd' || flag->type == 'i')
		result = ft_proc_d(va_arg(args, int), flag);
	if (flag->type == 'u')
		result = ft_proc_u(va_arg(args, int), flag);
	if (flag->type == 'c')
		result = ft_proc_c(va_arg(args, int), flag);
	if (flag->type == 's')
		result = ft_proc_s(va_arg(args, char*), flag);
	if (flag->type == 'x' || flag->type == 'X')
		result = ft_proc_hex(va_arg(args, unsigned int), flag);
	if (flag->type == 'p')
		result = ft_proc_p(va_arg(args, unsigned long int), flag);
	if (flag->type == '%')
		result = ft_proc_percent(flag);
	return (result);
}
