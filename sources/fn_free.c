/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:24:56 by juasanto          #+#    #+#             */
/*   Updated: 2022/12/12 13:19:45 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_list(t_list *list)
{
	if (list)
	{
		ft_free_list(list->next);
		free(list);
	}
}

void	ft_free_enve(t_envel *envlist)
{
	if (envlist)
	{
		envlist->name = NULL;
		envlist->value = NULL;
	}
}

void	ft_free_exe(t_exe *execommands)
{
	if (execommands)
	{
		execommands->cmd = NULL;
		ft_free_array(execommands->args);
	}
}

void	ft_lstdelone(t_list *commands, void (*del)(void *))
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
			ft_lstdelone(*commands, del);
			(*commands) = temp;
		}
	}
}

void	ft_free_tokens(t_token *tokens)
{
	if (!tokens->extvar)
		return ;
	ft_free_array(&tokens->extvar);
}

void	ft_freemain(t_main *main)
{
	free(main->line);
	free(main->home);
	free(main->temp_pwd);
	free(main->temp_oldpwd);
	ft_free_list(main->commands);
	ft_free_tokens(main->tokens);
	ft_free_list(main->envl);
	ft_free_enve(main->envlist);
	free(main);
}
