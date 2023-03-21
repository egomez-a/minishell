/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:01:44 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/21 14:34:29 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_builtins(t_main *main)
{
	char	*cmd;

	cmd = main->exe_commands->cmd;
	if (ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "exit") == 0)
		return (1);
	else
		return (0);
}

void	fn_check_word(t_list *list, t_main *main)
{
	if (ft_strcmp((((t_token *)list->content)->word), "pwd") == 0)
		main->ret = fn_pwd();
	else if (ft_strcmp((((t_token *)list->content)->word), "env") == 0)
		main->ret = fn_env(main);
	else if (ft_strcmp((((t_token *)list->content)->word), "export") == 0)
		main->ret = fn_export(main);
	else if (ft_strcmp((((t_token *)list->content)->word), "cd") == 0)
		main->ret = fn_cd(main);
	else if (ft_strcmp((((t_token *)list->content)->word), "echo") == 0)
		main->ret = fn_echo(main, 0);
	else if (ft_strcmp((((t_token *)list->content)->word), "exit") == 0)
	 	main->ret = fn_exit(main);
	else if (ft_strcmp((((t_token *)list->content)->word), "unset") == 0)
		main->ret = fn_unset(main);
}
