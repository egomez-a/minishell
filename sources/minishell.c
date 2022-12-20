/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:51:25 by juasanto          #+#    #+#             */
/*   Updated: 2022/12/20 12:46:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		fn_exe_cm(t_main *main)
{
	main->pid.p1 = fork();
	if (main->pid.p1 < 0)
		perror("Error Fork P1\n");
	if (main->pid.p1 == 0)
		execve("pwd", NULL, main->env);
	return (0);
}

void	check_first_token(t_main *main)
{
	char	**argument_list;
	char 	**paths_matrix;
	char	**first_token_with_path;
	int 	i;

	argument_list = main->exe_commands->args;
	paths_matrix = paths_from_env(main);
	first_token_with_path = ft_calloc(ft_matrixlen(paths_matrix) + 1, sizeof(char *));
	i = 0;
	while (i < ft_matrixlen(paths_matrix))
	{
		first_token_with_path[i] = ft_strjoin(paths_matrix[i], (((t_token *)main->commands->content)->word));
		i++;
	}
	i = 0;
	while (i < ft_matrixlen(paths_matrix))
	{
		if (access(first_token_with_path[i], X_OK)  == 0)
			break;
		i++;
	}
	printf ("El path %d %s se puede leer", i, first_token_with_path[i]);
	if (execve(first_token_with_path[i], argument_list, NULL) != -1)
		printf("1er token %s SI se puede ejecutar\n", first_token_with_path[i]);
	free(argument_list);
	free(first_token_with_path);
	free(paths_matrix);
}

void	export_token(t_main *main)
{
	t_list		*tokens;
	int			n_list;

	tokens = (t_list *)main->commands;
	first_token_cmd(tokens);
	print_list(tokens);
	n_list = ft_lstsize(tokens);
	main->exe_commands = ft_calloc(sizeof (t_exe), n_list);
	main->exe_commands->cmd = ((t_token *)tokens->content)->word;
	main->exe_commands->args = args_list_into_matrix(main);
	main->exe_commands->fd_in = ((t_token *)tokens->content)->fd;
	main->exe_commands->fd_out = ((t_token *)tokens->content)->fd;
}

int	main(int argc, char **argv, char **env)
{
	t_main	*main;

	main = NULL;
	main = fn_init_main(main, argc, argv, env);
	ft_env_list(main, env);
	while (1)
	{
		main->line = check_prompt(argc, argv);
		if (main->line[0] != '\0')
		{
			main->lenght_line = ft_strlen(main->line);
			if (main->line[0] == '9')
				break;
			if (fn_clean_quotes(main) != 0)
			{
				printf("Número impar de quotes\n");
				main->ret = 1;
				exit(255); //TODO: Llevar a mensaje de error.
			}
			main->tokens = fn_token_list(main);
			export_token(main);
			if (check_builtins(main) == 1)
				fn_check_word(main->commands, main);
			else
				check_first_token(main);
		}
		free(main->line);
		ft_lstclear(&main->commands, ft_free_token);
		ft_free_array(main->exe_commands->args);
	}
	ft_freemain(main);
	system("leaks -q minishell");
	return (0);
}
