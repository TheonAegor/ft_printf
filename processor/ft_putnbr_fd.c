/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:52:25 by taegor            #+#    #+#             */
/*   Updated: 2021/01/16 11:39:08 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_putnbr_u(unsigned x)
{
	static int	res;
	
	if (x < 10)
	{
		x += 48;
		res += ft_putchar(x);
		return ;
	}
	else
		ft_putnbr_u(x/10, fd);
	x = (x % 10) + 48;
	res += ft_putchar(x);
}
