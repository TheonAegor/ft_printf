/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:08:51 by heula             #+#    #+#             */
/*   Updated: 2020/11/09 22:54:17 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	n;

	if (!s1)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((res = (char *)malloc(sizeof(const char) * (len + 1))) == NULL)
		return (0);
	n = ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	n = ft_strlcat(res, s2, len + 1);
	return (res);
}
