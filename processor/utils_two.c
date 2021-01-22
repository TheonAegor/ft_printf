/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:52:40 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 13:53:48 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_minus(s_modif *flag)
{
	char	*tmp;

	if (*flag->variable == '-' && ((flag->flag == 1 ||
		flag->width <= 0) ||
		(flag->flag == 2)))
	{
		ft_putchar('-');
		tmp = flag->variable;
		flag->variable = ft_strdup(&flag->variable[1]);
		free(tmp);
		return (1);
	}
	return (0);
}

int		revers(char **str)
{
	int		i;
	int		n;
	char	tmp;
	char	*dup;

	dup = *str;
	i = 0;
	n = ft_strlen(*str) - 1;
	while (i < (int)ft_strlen(dup) / 2)
	{
		tmp = dup[i];
		dup[i++] = dup[n];
		dup[n--] = tmp;
	}
	return (1);
}

char	*ft_itoa_base(unsigned long long int x)
{
	char	*hex;
	int		i;
	int		n;
	char	*ptr;

	hex = "0123456789abcdef";
	n = x > 0 ? x : (-1) * x;
	i = 1;
	while ((n = n / 16) > 0)
		i++;
	if ((ptr = ft_calloc(sizeof(char), i + 1)) == NULL)
		return (0);
	i = 0;
	if (x == 0)
		ptr[i++] = '0';
	while (x > 0)
	{
		ptr[i] = hex[x % 16];
		x = (x / 16);
		i++;
	}
	ptr[i] = '\0';
	revers(&ptr);
	return (ptr);
}
