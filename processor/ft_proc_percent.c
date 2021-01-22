/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:37:55 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:37:58 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proc_percent(s_modif *flag)
{
	if ((flag->variable = ft_calloc(sizeof(char), 2)) == NULL)
		return (-1);
	flag->variable[0] = '%';
	flag->variable[1] = '\0';
	flag->result++;
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
