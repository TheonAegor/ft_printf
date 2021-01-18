/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:24:09 by heula             #+#    #+#             */
/*   Updated: 2020/11/08 19:48:27 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	if (dst == NULL && src == NULL)
		return (0);
	dst1 = (char *)dst;
	src1 = (char *)src;
	if (dst1 > src1 && dst1 < src1 + len)
	{
		while (len--)
		{
			dst1[len] = src1[len];
		}
	}
	else
		dst1 = ft_memcpy(dst1, src1, len);
	return (dst);
}
