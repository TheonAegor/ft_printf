/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:13:50 by heula             #+#    #+#             */
/*   Updated: 2020/11/14 23:29:28 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*memory(int n)
{
	char		*res;
	int			i;

	i = (n == 0) ? 1 : 0;
	if (n == -2147483648)
	{
		i++;
		n = -147483648;
	}
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	if ((res = ft_calloc(i + 1, sizeof(char))) == NULL)
		return (0);
	while (--i >= 0)
		res[i] = '1';
	return (res);
}

char		*ft_itoa(int n)
{
	char			*res;
	size_t			i;

	if ((res = memory(n)) == NULL)
		return (0);
	i = ft_strlen(res);
	if (n == -2147483648)
	{
		res[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		res[0] = '-';
		n = n * (-1);
	}
	res[i] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--i] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
