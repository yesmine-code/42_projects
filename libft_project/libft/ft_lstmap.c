/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybesbes <ybesbes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 22:17:56 by ybesbes           #+#    #+#             */
/*   Updated: 2020/05/24 23:12:40 by ybesbes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*element;

	if (lst == NULL || !(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	while (lst)
	{
		if (!(element = ft_lstnew((*f)(lst->content))))
		{
			ft_lstadd_back(&new, element);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
	}
	return (new);
}
