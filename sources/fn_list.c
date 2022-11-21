/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:13:05 by juasanto          #+#    #+#             */
/*   Updated: 2022/05/20 12:55:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// t_token	*fn_lstnew(void *content)
// {
// 	t_token	*new_content;

// 	new_content = (t_token *)malloc(sizeof(*new_content));
// 	if (!new_content)
// 		return (NULL);
// 	new_content->content = content;
// 	new_content->next = NULL;
// 	return (new_content);
// }

// int	fn_lstsize(t_list *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		i++;
// 	}
// 	return (i);
// }

// t_token	*fn_lstlast(t_token *lst)
// {
// 	while (lst != 0)
// 	{
// 		if (lst->next == 0)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// void	fn_lstadd_back(t_token **lst, t_token *new_l)
// {
// 	t_token	*last;

// 	if (lst != 0)
// 	{
// 		if (*lst != 0)
// 		{
// 			last = fn_lstlast(*lst);
// 			last->next = new_l;
// 		}
// 		else
// 			*lst = new_l;
// 	}
// }

// void	fn_lstdelone(t_token *token, void (*del)(void *))
// {
// 	del(token->content);
// 	free(token);
// 	token = NULL;
// }
