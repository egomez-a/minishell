/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:22:24 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:44:35 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if (lst)
	{
		pointer = *lst;
		if (pointer == NULL)
			*lst = new;
		else
		{
			while (pointer->next != NULL)
				pointer = pointer->next;
			pointer->next = new;
		}
	}
}
