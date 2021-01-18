/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:07:11 by heula             #+#    #+#             */
/*   Updated: 2020/11/14 21:11:55 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clearing(size_t trigger, char **res)
{
	size_t	j;

	j = 0;
	if (trigger == 0)
	{
		free(res);
	}
	if (trigger == 1)
	{
		while (res[j])
			free(res[j++]);
		clearing(0, res);
	}
}

static char	**lines_mem_alloc(char const *s, char c)
{
	size_t	j;
	size_t	k;
	char	**res;

	k = 0;
	j = 0;
	while (s[j++] != '\0')
		if (s[j] == c && (s[j - 1] != c))
			k++;
	if (s[j - 1] != c)
		k++;
	if (ft_strlen(s) == 1 && s[0] != c)
		k = 1;
	if ((res = ft_calloc(k + 1, sizeof(char*))) == NULL)
	{
		clearing(0, res);
		return (0);
	}
	return (res);
}

static char	**arr_mem_alloc(char **res, const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	j = 0;
	while (s[k] != '\0')
	{
		i = 0;
		while (s[k] != c && s[k] != '\0')
		{
			i++;
			k++;
		}
		if (i == 0)
		{
			k++;
			continue;
		}
		if ((res[j++] = ft_substr(s, k - i, i)) == NULL)
			return (0);
		res[j] = 0;
	}
	return (res);
}

char		**ft_split(char const *s, char c)
{
	size_t	j;
	char	**res;

	j = 0;
	if (!s)
		return (0);
	res = lines_mem_alloc(s, c);
	if (!res)
		return (0);
	if ((res = arr_mem_alloc(res, s, c)) == NULL)
	{
		clearing(1, res);
		return (0);
	}
	return (res);
}
