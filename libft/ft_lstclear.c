/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdabdul <abdabdul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:19:37 by abdabdul          #+#    #+#             */
/*   Updated: 2022/05/21 15:19:37 by abdabdul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		node = *lst;
		*lst = node->next;
		free(node);
	}
	*lst = NULL;
}
