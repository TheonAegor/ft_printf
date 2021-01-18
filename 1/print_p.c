/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 19:38:23 by heula             #+#    #+#             */
/*   Updated: 2021/01/13 19:50:06 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	p_string(t_mode *format, char *tmp, int i)
{
	char	*output;
	int		len;

	len = ft_strlen(tmp);
	if ((output = (char *)malloc((format->width + 1) * sizeof(char))) == NULL)
		return (-1);
	ft_memmove(output, "0x", 2);
	output[2] = '\0';
	if ((ft_strncmp(tmp, "0", ft_strlen(tmp))) == 0 && format->accuracy == 0)
		format->width = i > 2 ? i : 2;
	else
		ft_memmove(&output[2], tmp, ft_strlen(tmp));
	output[len + 2] = '\0';
	accuracy_num(format, output);
	ft_putstr_fd(output, 1);
	i = ft_strlen(output);
	free(output);
	return (i);
}

int	print_p(t_mode *format)
{
	char	*tmp;
	int		i;

	i = format->width;
	if ((tmp = itoa_base(va_arg(format->s, unsigned long long int))) == 0)
		return (-1);
	format->width = format->width > (int)ft_strlen(tmp) + 2 ?
	format->width : (int)ft_strlen(tmp) + 2;
	format->width = format->width > format->accuracy ?
	format->width : format->accuracy;
	if ((i = p_string(format, tmp, i)) == -1)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i);
}
