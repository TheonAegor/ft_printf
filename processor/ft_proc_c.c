/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:46:28 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:31:21 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proc_c(int c, s_modif *flag)
{
	if ((flag->variable = ft_calloc(sizeof(char), 2)) == NULL)
		return (-1);
	flag->variable[0] = c;
	flag->variable[1] = '\0';
	flag->result++;
	if (c == '\0')
		flag->width -= 1;
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
