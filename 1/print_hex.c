/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:07:59 by heula             #+#    #+#             */
/*   Updated: 2021/01/13 19:48:49 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	hex_string(t_mode *format, char *tmp)
{
	char	*output;
	int		i;

	if ((output = (char *)malloc(format->width + 1)) == NULL)
		return (-1);
	if (format->accuracy != -1 && format->flag == '0')
		format->flag = '1';
	ft_memmove(output, tmp, ft_strlen(tmp));
	output[ft_strlen(tmp)] = '\0';
	accuracy_num(format, output);
	ft_putstr_fd(output, 1);
	i = ft_strlen(output);
	free(output);
	free(tmp);
	return (i);
}

int	print_hex(t_mode *format)
{
	char					*tmp;
	unsigned long long int	i;

	i = va_arg(format->s, unsigned int);
	if ((tmp = itoa_base(i)) == 0)
		return (-1);
	if (i == 0 && (format->accuracy == 0))
		*tmp = '\0';
	i = -1;
	if (format->type == 'X')
		while (tmp[++i] != '\0')
			tmp[i] = (char)ft_toupper((int)tmp[i]);
	format->width = format->width > (int)ft_strlen(tmp) ?
	format->width : (int)ft_strlen(tmp);
	format->width = format->width > format->accuracy ?
	format->width : format->accuracy;
	if ((i = hex_string(format, tmp)) == -1)
	{
		free(tmp);
		return (-1);
	}
	return (i);
}
