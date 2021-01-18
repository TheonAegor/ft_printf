/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:13:03 by heula             #+#    #+#             */
/*   Updated: 2021/01/12 23:57:24 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	reverse_line(char **output)
{
	int		i;
	int		l;
	char	tmp;
	char	*copy;

	copy = *output;
	i = 0;
	l = ft_strlen(*output) - 1;
	while (i < (int)ft_strlen(copy) / 2)
	{
		tmp = copy[i];
		copy[i++] = copy[l];
		copy[l--] = tmp;
	}
}

char	*itoa_base(unsigned long long int num)
{
	char	*hex;
	int		i;
	int		n;
	char	*ptr;

	hex = "0123456789abcdef";
	n = num > 0 ? num : (-1) * num;
	i = 1;
	while ((n = n / 16) > 0)
		i++;
	if ((ptr = (char*)malloc((i + 1) * sizeof(char))) == NULL)
		return (0);
	i = 0;
	if (num == 0)
		ptr[i++] = '0';
	while (num > 0)
	{
		ptr[i] = hex[num % 16];
		num = (num / 16);
		i++;
	}
	ptr[i] = '\0';
	reverse_line(&ptr);
	return (ptr);
}

void	flags_width_num(t_mode *format, char *output)
{
	int		diff;
	char	*minus;

	diff = format->width - ft_strlen(output);
	if (format->flag == '-')
		printspace(&output[ft_strlen(output)], diff);
	if (format->flag == '1')
	{
		ft_memmove(&output[diff], output, ft_strlen(output) + 1);
		printspace(output, diff);
	}
	if (format->flag == '0')
	{
		ft_memmove(&output[diff], output, ft_strlen(output) + 1);
		printzero(output, diff);
		if ((minus = ft_strchr(output, '-')) != NULL)
		{
			*minus = '0';
			*output = '-';
		}
	}
	output[format->width] = '\0';
}

void	accuracy_num(t_mode *format, char *output)
{
	char	*mem;
	int		i;

	i = (*output == '-') ? ft_strlen(output) - 1 : ft_strlen(output);
	mem = (*output == '-') ? &output[1] : output;
	mem = (ft_strncmp(output, "0x", 2) == 0) ? &output[2] : mem;
	if (i < format->accuracy)
	{
		if (*output == '-')
			ft_memmove(&output[format->accuracy - i + 1], mem, i + 1);
		else
			ft_memmove(&output[format->accuracy - i], mem, i + 1);
		printzero(mem, format->accuracy - i);
	}
	if (format->width > (int)ft_strlen(output))
		flags_width_num(format, output);
}
