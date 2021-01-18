/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:19:57 by heula             #+#    #+#             */
/*   Updated: 2020/11/17 21:18:08 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hsk, const char *ndl, size_t len)
{
	size_t i;
	size_t k;

	i = 0;
	if (ndl[0] == '\0')
		return ((char*)&hsk[0]);
	while (hsk[i] != '\0' && i < len)
	{
		k = 0;
		while (hsk[i] == ndl[k] && ndl[k] != '\0')
		{
			i++;
			k++;
		}
		if (ndl[k] == '\0' && i <= len)
			return ((char*)&hsk[i - k]);
		if (k == 0)
			i++;
		else
			i = i - k + 1;
	}
	return (0);
}
