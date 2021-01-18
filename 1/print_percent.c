/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:34:16 by heula             #+#    #+#             */
/*   Updated: 2021/01/12 21:50:58 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int	print_percent(t_mode *format)
{
	char	*output;
	int		i;

	format->width = format->width > 1 ? format->width : 1;
	if ((output = (char *)malloc(format->width + 1)) == NULL)
		return (-1);
	output[0] = '%';
	output[1] = '\0';
	flags_width_num(format, output);
	ft_putstr_fd(output, 1);
	i = ft_strlen(output);
	free(output);
	return (i);
}
