/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 18:38:58 by heula             #+#    #+#             */
/*   Updated: 2020/11/15 20:31:38 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t k;

	k = 0;
	len = ft_strlen(dst);
	if (!src[k])
		return (len);
	if (len >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[k] && len + k < dstsize - 1)
	{
		dst[len + k] = src[k];
		k++;
	}
	if (len <= dstsize - 1)
		dst[len + k] = '\0';
	return (ft_strlen(src) + len);
}
