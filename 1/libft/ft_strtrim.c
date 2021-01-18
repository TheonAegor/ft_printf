/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 22:08:51 by heula             #+#    #+#             */
/*   Updated: 2020/11/16 23:14:31 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_leight(char const *s1, char const *set)
{
	size_t i;
	size_t l;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (i == ft_strlen(s1) - 1)
		return (0);
	l = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[l]) != NULL)
		l--;
	l = l - i + 1;
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	if ((len = str_leight(s1, set)) == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	if ((res = ft_substr(s1, i, len)) == NULL)
		return (0);
	return (res);
}
