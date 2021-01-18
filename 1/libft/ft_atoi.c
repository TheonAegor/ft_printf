/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:23:22 by heula             #+#    #+#             */
/*   Updated: 2020/11/07 22:50:34 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	res;
	int					i;
	int					minus;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = -1;
	while (ft_isdigit(str[i]) == 1)
	{
		if (minus == -1 && res > 9223372036854775807)
			return (0);
		if (res > 9223372036854775807)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)res * minus);
}
