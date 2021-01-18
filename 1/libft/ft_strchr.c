/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:31:39 by heula             #+#    #+#             */
/*   Updated: 2020/11/07 15:32:15 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = (char*)s;
	while (result[i] != '\0' || c == '\0')
	{
		if (result[i] == c)
			return (&result[i]);
		else
			i++;
	}
	return (0);
}
