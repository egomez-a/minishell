/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:22:20 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:45:06 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		listlen;

	if (!lst)
		listlen = 0;
	else
	{
		listlen = 0;
		while (lst != NULL)
		{
			listlen++;
			lst = lst->next;
		}
	}
	return (listlen);
}
