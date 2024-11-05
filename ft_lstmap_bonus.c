/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:11:59 by asene             #+#    #+#             */
/*   Updated: 2024/11/05 13:45:47 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_item;

	if (!lst || !f || !del)
		return (NULL);
	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->next = NULL;
	while (lst)
	{
		new_item = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new_list, new_item);
		lst = lst->next;
	}
	return (new_list);
}
