/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:19:36 by heula             #+#    #+#             */
/*   Updated: 2021/01/13 19:20:31 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	print_d_i(t_mode *format)
{
	char	*output;
	char	*arg;
	int		i;

	i = va_arg(format->s, unsigned int);
	if ((arg = ft_itoa(i)) == NULL)
		return (-1);
	if (i == 0 && (format->accuracy == 0))
		*arg = '\0';
	format->width = format->width > (int)ft_strlen(arg) ?
	format->width : (int)ft_strlen(arg);
	format->width = format->width > format->accuracy ?
	format->width : format->accuracy;
	if ((output = (char *)malloc(format->width + 1)) == NULL)
		return (-1);
	if (format->accuracy != -1 && format->flag == '0')
		format->flag = '1';
	ft_memmove(output, arg, ft_strlen(arg));
	output[ft_strlen(arg)] = '\0';
	accuracy_num(format, output);
	ft_putstr_fd(output, 1);
	i = ft_strlen(output);
	free(output);
	free(arg);
	return (i);
}
