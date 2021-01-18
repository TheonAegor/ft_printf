/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 20:13:07 by heula             #+#    #+#             */
/*   Updated: 2020/11/20 23:09:11 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *newlist;
	t_list *newelmnt;

	if (!lst)
		return (0);
	if ((newlist = ft_lstnew(f(lst->content))) == NULL)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((newelmnt = ft_lstnew(f(lst->content))) == NULL)
			ft_lstclear(&newlist, del);
		else
			ft_lstadd_back(&newlist, newelmnt);
	}
	return (newlist);
}
