/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:37:19 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:11:18 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proc_p(unsigned long int x, t_modif *flag)
{
	long long int				category;
	unsigned long int			tmp;

	category = ft_find_sixteens(x) + 2;
	flag->variable = ft_calloc(sizeof(char), category + 2);
	flag->variable[category--] = '\0';
	flag->result += 2;
	while (category > 1)
	{
		tmp = x % 16;
		if (tmp < 10)
			flag->variable[category--] = tmp + 48;
		if (tmp >= 10 && tmp <= 15)
			flag->variable[category--] = (((tmp + 1) % 10) | 48) ^ 80;
		flag->result++;
		x = x / 16;
	}
	flag->variable[category--] = 'x';
	flag->variable[category] = '0';
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
