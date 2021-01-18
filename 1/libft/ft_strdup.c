/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:04:38 by heula             #+#    #+#             */
/*   Updated: 2020/11/09 20:18:09 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s1);
	if ((buf = (char *)malloc(sizeof(const char) * (len + 1))) == NULL)
		return (0);
	buf[len] = '\0';
	while (len--)
		buf[len] = s1[len];
	return (buf);
}
