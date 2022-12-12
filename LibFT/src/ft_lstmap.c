/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:05:06 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:38:22 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*item_lst;

	item_lst = 0;
	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->content));
		if (!new_list)
		{
			ft_lstclear(&item_lst, del);
			return (0);
		}
		ft_lstadd_back(&item_lst, new_list);
		lst = lst->next;
	}
	return (item_lst);
}
