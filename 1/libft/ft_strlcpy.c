/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:38:58 by heula             #+#    #+#             */
/*   Updated: 2020/11/07 22:30:13 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	if (!dst || !src)
		return (0);
	while (src[i] != '\0')
		i++;
	if (dstsize != 0)
	{
		while (k < i && k < (dstsize - 1))
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = '\0';
	}
	return (i);
}
