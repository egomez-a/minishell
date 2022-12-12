/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:32:04 by juasanto          #+#    #+#             */
/*   Updated: 2022/12/12 13:16:41 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*chk_here1(t_main *main, int cnt)
{
	t_token		*new_token;

	if (main->line[cnt] == '<' && main->line[cnt + 1] == '<')
	{
		new_token = fn_token_new("<<", HERE, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 2)) + 2;
	}
	if (main->line[cnt] == '>' && main->line[cnt + 1] == '>')
	{
		new_token = fn_token_new(">>", APPEND, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 2)) + 2;
	}
	return (NULL);
}

t_main	*fn_init_main(t_main *main, int argc, char **argv, char **env)
{
	main = ft_calloc(sizeof(t_main), 1);
	main->argc = argc;
	main->argv = argv;
	main->env = env;
	main->envl = NULL;
	main->ret = 0;   //variable de retorno 
	main->exe_commands = NULL;
	main->control = 0;    //si las variables de entorno estan borradas pasa a ser 1
	// main->func[0] = (t_func){60, chk_here1(main, 4)};
	return (main);
}

int		fn_clean_quotes(t_main *main)
{
	int		cnt;
	int		tmp_quote;
	int		find_quote;

	cnt = -1;
	tmp_quote = 0;
	find_quote = 0;
	while (++cnt < main->lenght_line)
	{
		if ((main->line[cnt] == DQU || main->line[cnt] == SQU) && \
				find_quote == 0)
		{
			tmp_quote = (int)main->line[cnt];
			find_quote = 1;
			cnt++;
		}
		if (main->line[cnt] == tmp_quote && find_quote == 1)
			find_quote = 0;
	}
	return (find_quote);
}

char	*check_prompt(int argc, char **argv)
{
	char	*prompt;

	(void)argc;
	(void)argv;
	prompt = readline("\033[36mprompt:\\ (Salimos con 9)> \033[0m");
	if (!prompt)
		exit(0);
	if (prompt[0] != '\0')
		add_history(prompt);
	return (prompt);
}
