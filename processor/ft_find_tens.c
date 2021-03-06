/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_tens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:30:13 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:30:15 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned	ft_tens(unsigned long n)
{
	unsigned		i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static unsigned	ft_sqrt(unsigned long num, unsigned i)
{
	while (i > 0)
	{
		num = num * 10;
		i--;
	}
	return (num);
}

int				ft_find_tens(unsigned long int x)
{
	if (x == 0)
		return (1);
	return (ft_tens(x));
}
