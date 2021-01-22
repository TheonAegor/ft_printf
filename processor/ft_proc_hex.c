/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:33:18 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:10:55 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_proc_hex(unsigned int x, t_modif *flag)
{
	char			*tmp;
	int				i;

	if ((tmp = ft_itoa_base(x)) == NULL)
		return (-1);
	if (x == 0 && (flag->precision == 0))
		*tmp = '\0';
	i = -1;
	if (flag->type == 'X')
		while (tmp[++i] != '\0')
			tmp[i] = (char)(ft_toupper((int)tmp[i]));
	flag->variable = ft_strdup(tmp);
	free(tmp);
	flag->result += ft_strlen(flag->variable);
	ft_calc_flags(flag);
	print_flags(flag);
	return (1);
}
