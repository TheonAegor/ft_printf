/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:46:50 by heula             #+#    #+#             */
/*   Updated: 2020/11/15 16:10:46 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	exceptions(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		num;
	char	c;

	num = n;
	len = 1;
	if (exceptions(n, fd) == 1)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		num = num * (-1);
		n = num;
	}
	while ((num = num / 10) > 0)
	{
		len = len * 10;
	}
	while (len >= 1)
	{
		c = n / len + '0';
		write(fd, &c, 1);
		n = n % len;
		len = len / 10;
	}
}
