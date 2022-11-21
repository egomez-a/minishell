/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 11:13:59 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/18 12:29:29 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (f == 0)
		return ;
	while (lst != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
