/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:31:39 by heula             #+#    #+#             */
/*   Updated: 2020/11/07 16:00:43 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = ft_strlen(s);
	result = (char*)s;
	while (i >= 0 || c == '\0')
	{
		if (result[i] == c)
			return (&result[i]);
		else
			i--;
	}
	return (0);
}
