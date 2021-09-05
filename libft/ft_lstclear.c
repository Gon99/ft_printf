/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <goliano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:23:44 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/10 17:53:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del || !lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}
