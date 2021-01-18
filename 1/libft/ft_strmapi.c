/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 23:30:12 by heula             #+#    #+#             */
/*   Updated: 2020/11/15 12:47:17 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mapi;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((mapi = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))) != NULL)
	{
		while (s[i])
		{
			mapi[i] = f(i, s[i]);
			i++;
		}
		mapi[i] = '\0';
		return (mapi);
	}
	return (0);
}
