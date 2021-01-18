/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 23:39:05 by heula             #+#    #+#             */
/*   Updated: 2021/01/10 20:27:19 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	print_c(t_mode *format)
{
	char	*output;
	char	arg;

	if ((arg = va_arg(format->s, int)) == '\0')
	{
		if ((printifnull(format)) == -1)
			return (-1);
		return (format->width);
	}
	format->width = (format->width > 1) ? format->width : 1;
	if ((output = (char *)malloc(format->width + 1)) == NULL)
		return (-1);
	output[0] = arg;
	if (format->flag == '-')
		printspace(&output[1], format->width - 1);
	else
	{
		ft_memmove(&output[format->width - 1], output, 1);
		printspace(output, format->width - 1);
	}
	output[format->width] = '\0';
	ft_putstr_fd(output, 1);
	free(output);
	return (format->width);
}
