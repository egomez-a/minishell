/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:24:56 by juasanto          #+#    #+#             */
/*   Updated: 2023/03/27 12:39:50 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_envel(void *content)
{
	t_envel	*envel;

	if (!content)
		return ;
	envel = content;
	free(envel->name);
	free(envel->value);
	free(envel);
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

void 	ft_free_token(void *content)
{
	t_token	*token;

	if (!content)
		return ;
	token = content;
	free(token->word);
	free(token->extvar);
	free(token);
}

void	ft_freemain(t_main *main)
{
	free(main->line);
	free(main->home);
	free(main->temp_pwd);
	free(main->temp_oldpwd);
	ft_free_token(main->tokens);
	ft_lstclear(&main->envl, ft_free_envel);
	free(main->envlist);
	free(main->exe_commands);
	free(main);
}
