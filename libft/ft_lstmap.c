/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ennollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:55:29 by ennollet          #+#    #+#             */
/*   Updated: 2022/11/15 10:08:49 by ennollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	new_l = ft_lstnew(f(lst->content));
	if (!new_l)
		return (NULL);
	first = new_l;
	lst = lst->next;
	while (lst != NULL)
	{
		new_l->next = ft_lstnew(f(lst->content));
		if (!new_l->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new_l = new_l->next;
		lst = lst->next;
	}
	new_l->next = NULL;
	return (first);
}
