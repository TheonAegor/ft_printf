/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:45:13 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:30:51 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_unsigned(unsigned long x)
{
	char			*res;
	int				category;

	category = ft_find_tens(x);
	if ((res = ft_calloc(sizeof(char), category + 1)) == NULL)
		return (NULL);
	res[category--] = '\0';
	if (x == 0)
		res[0] = '0';
	while (x > 0)
	{
		res[category--] = (x % 10) + 48;
		x = x / 10;
	}
	return (res);
}
