/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:52:25 by taegor            #+#    #+#             */
/*   Updated: 2021/01/15 22:43:14 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_putnbr_u(unsigned x, int fd)
{
	if (x < 10)
	{
		x += 48;
		write(fd, &x, 1);
		return ;
	}
	else
		ft_putnbr_u(x/10, fd);
	x = (x % 10) + 48;
	write(fd, &x, 1);
}
