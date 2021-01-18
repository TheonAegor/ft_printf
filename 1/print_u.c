/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:29:35 by heula             #+#    #+#             */
/*   Updated: 2021/01/12 23:20:01 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*res;
	unsigned int	i;
	int				len;

	len = 0;
	i = n;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if ((res = (char*)malloc(len + 1)) == NULL)
		return (0);
	i = ft_strlen(res);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}

int		u_string(t_mode *format, char *arg)
{
	char	*output;
	int		i;

	if ((output = (char *)malloc(format->width + 1)) == NULL)
	{
		free(arg);
		return (-1);
	}
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

int		print_u(t_mode *format)
{
	char			*arg;
	unsigned int	i;
	int				result;

	i = va_arg(format->s, unsigned int);
	if ((arg = ft_itoa_unsigned(i)) == NULL)
		return (-1);
	if (i == 0 && (format->accuracy == 0))
		*arg = '\0';
	format->width = format->width > (int)ft_strlen(arg) ?
	format->width : (int)ft_strlen(arg);
	format->width = format->width > format->accuracy ?
	format->width : format->accuracy;
	if ((result = u_string(format, arg)) == -1)
		return (-1);
	return (result);
}
