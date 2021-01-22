/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:52:25 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:44:06 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_putnbr_u(unsigned x)
{
	static int	res;

	if (x < 10)
	{
		x += 48;
		res += ft_putchar(x);
	}
	else
	{
		ft_putnbr_u(x / 10);
		ft_putnbr_u(x % 10);
	}
	return (res);
}
