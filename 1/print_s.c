/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:10:51 by heula             #+#    #+#             */
/*   Updated: 2021/01/13 19:46:59 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		width_null_check(t_mode *format, char *arg, char **output)
{
	if (ft_strncmp(arg, "\0", ft_strlen(arg)) == 0)
	{
		if (format->width == -1)
		{
			free(*output);
			return (1);
		}
	}
	return (0);
}

int		print_s_parttwo(t_mode *format, char **result)
{
	int		diff;
	char	*output;

	output = *result;
	output[format->accuracy] = '\0';
	format->width = (format->width > (int)ft_strlen(output)) ?
	format->width : (int)ft_strlen(output);
	diff = format->width - ft_strlen(output);
	if (format->flag == '1')
	{
		ft_memmove(&output[diff], output, ft_strlen(output));
		printspace(output, diff);
	}
	if (format->flag == '-')
		printspace(&output[ft_strlen(output)], diff);
	if (format->flag == '0')
	{
		ft_memmove(&output[diff], output, ft_strlen(output));
		printzero(output, diff);
	}
	output[format->width] = '\0';
	ft_putstr_fd(output, 1);
	format->width = ft_strlen(output);
	free(output);
	return (format->width);
}

int		print_s(t_mode *format)
{
	char	*output;
	char	*arg;
	int		diff;

	arg = va_arg(format->s, char *);
	if (arg == NULL)
		arg = "(null)";
	diff = (format->width > (int)ft_strlen(arg)) ?
	format->width : (int)ft_strlen(arg);
	if ((output = (char *)malloc(diff + 1)) == NULL)
		return (-1);
	if ((width_null_check(format, arg, &output)) == 1)
		return (0);
	if (format->accuracy != -1)
	{
		format->accuracy = (format->accuracy < (int)ft_strlen(arg)) ?
		format->accuracy : (int)ft_strlen(arg);
	}
	else
		format->accuracy = (int)ft_strlen(arg);
	ft_memmove(output, arg, format->accuracy);
	diff = print_s_parttwo(format, &output);
	return (diff);
}
