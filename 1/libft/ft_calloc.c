/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:33:49 by heula             #+#    #+#             */
/*   Updated: 2020/11/09 20:02:03 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char *buf;

	if ((buf = (char *)malloc(count * size)) == NULL)
		return (0);
	ft_bzero(buf, count * size);
	return ((void *)buf);
}
