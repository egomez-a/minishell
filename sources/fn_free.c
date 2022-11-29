/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:24:56 by juasanto          #+#    #+#             */
/*   Updated: 2022/11/29 15:39:21 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	fn_free_tokens(t_token *tokens)
{
	if (!tokens->extvar)
		return;
	ft_free_array(&tokens->extvar);	
}

void	fn_free_exe(t_exe *exe_commands)
{
	if (!exe_commands->args)
		return;
	ft_free_array(exe_commands->args);	
}

void	fn_free_envlist(t_envel *envel)
{
	if (envel->name)
		envel->name = NULL;
	if (envel->value)
		envel->value = NULL;
}

void	fn_free(t_main *main)
{
	if (main->line)
		free(main->line);
	if (main->home)
		free(main->home);
	if (main->temp_pwd)
		free(main->temp_pwd);
	if (main->temp_oldpwd)
		free(main->temp_oldpwd);
	if (main->commands)
		ft_free_list(main->commands);
	if (main->tokens)
		fn_free_tokens(main->tokens);
	// if (main->exe_commands)
	// 	ft_free_exe(main->exe_commands);
	if (main->envl)
		ft_free_list(main->envl);
	if (main->envlist)
		fn_free_envlist(main->envlist);
	if (main)
		free(main);
}
