/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 12:56:27 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/18 12:29:28 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = (t_list *)malloc(sizeof(*new_content));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
