/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:24:45 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:44:46 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pointer;
	t_list	*current;

	current = *lst;
	while (current)
	{
		pointer = current->next;
		(*del)(current->content);
		free(current);
		current = pointer;
	}
	(*lst) = NULL;
}
