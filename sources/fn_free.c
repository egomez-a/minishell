/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:24:56 by juasanto          #+#    #+#             */
/*   Updated: 2022/09/29 15:11:10 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fn_free_struct(t_main *stru)
{
	if (!stru)
		return ;
	free(stru);
	stru = NULL;
}

void	fn_lstdelone(t_list *commands, void (*del)(void *))
{
	free(((t_token *)commands->content)->word);
	del(commands->content);
	free(commands);
	commands = NULL;
}

void	ft_tokenclear(t_list **commands, void (*del)(void *))
{
	t_list	*temp;

	if (commands)
	{
		while (*commands)
		{
			temp = (*commands)->next;
			fn_lstdelone(*commands, del);
			(*commands) = temp;
		}
	}
}

void	fn_free(t_main *main)
{
	free(main->line);
	ft_tokenclear(&main->commands, free);
	ft_tokenclear(&main->envl, free);
	fn_free_struct(main);
}
