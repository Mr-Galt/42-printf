/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 20:18:24 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/12 16:34:04 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp_node = ft_lstnew((*f)(lst->content));
		if (!temp_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, temp_node);
		temp_node = temp_node->next;
		lst = lst->next;
	}
	return (new_list);
}
