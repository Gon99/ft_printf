/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:47:15 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/06 17:07:52 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*content;

	if (!lst)
		return (NULL);
	aux = NULL;
	while (lst)
	{
		content = ft_lstnew(f(lst->content));
		if (!content)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		ft_lstadd_back(&aux, content);
		lst = lst->next;
	}
	return (aux);
}
