/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sixteens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:29:20 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:29:49 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_find_sixteens(unsigned long x)
{
	unsigned i;

	i = 0;
	if (x == 0)
		return (1);
	while (x)
	{
		x = x / 16;
		i++;
	}
	return (i);
}
