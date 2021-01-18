/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:05:45 by heula             #+#    #+#             */
/*   Updated: 2020/11/20 20:39:00 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *clear1;
	t_list *clear2;

	clear1 = *lst;
	while (clear1->next != NULL)
	{
		del(clear1->content);
		clear2 = clear1->next;
		free(clear1);
		clear1 = clear2;
	}
	del(clear1->content);
	free(clear1);
	*lst = NULL;
}
