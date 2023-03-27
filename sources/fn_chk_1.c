/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_chk_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 12:19:58 by juasanto          #+#    #+#             */
/*   Updated: 2023/03/27 12:47:59 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//TODO: Controlar el $ para expandir variables.

int	chk_here(t_main *main, int cnt) 
{
	t_token		*new_token;

	if (main->line[cnt] == LESS && main->line[cnt + 1] == LESS)
	{
		new_token = fn_token_new("<<", HERE, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 2)) + 2;
	}
	if (main->line[cnt] == MORE && main->line[cnt + 1] == MORE)
	{
		new_token = fn_token_new(">>", APPEND, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 2)) + 2;
	}
	return (cnt);
}

int	chk_redirect(t_main *main, int cnt)
{
	t_token		*new_token;

	if (main->line[cnt] == LESS)
	{
		new_token = fn_token_new("<", RD, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 1)) + 1;
	}
	if (main->line[cnt] == MORE)
	{
		new_token = fn_token_new(">", RD, 1, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt = (cnt + word_nam(main, ARG, 32, cnt + 1)) + 1;
	}
	return (cnt);
}

int	chk_pipe(t_main *main, int cnt)
{
	t_token		*new_token;

	if (main->line[cnt] == PIPE)
	{
		new_token = fn_token_new("|", PIPE, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt++;
	}
	return (cnt);
}

int	chk_quote(t_main *main, int cnt)
{
	t_token		*new_token;
	int			tmp_quote;
	char		*word;
	char 		add_one[2];
	int 		flag;

	flag = ARG;
	word = ft_strdup("");
	add_one[1] = 0;
	if (main->line[cnt] == DQU || main->line[cnt] == SQU)
	{
		tmp_quote = (int)main->line[cnt];
		cnt++;
		while ((main->line[cnt] != tmp_quote) && (main->line[cnt + 1] != SPACE
				|| main->line[cnt + 1] != DQU || main->line[cnt + 1] != SQU
				|| main->line[cnt + 1] != PIPE || main->line[cnt + 1] != LESS
				|| main->line[cnt + 1] != MORE) && cnt < main->lenght_line)
		{
			if (main->line[cnt - 1] == DQU && main->line[cnt] == DOLLAR)
			{	
				flag = DOLARG;
				cnt++;
			}
			add_one[0] = main->line[cnt];
			word = ft_strjoin_clean(word, add_one, 1);
			cnt++;
			if ((main->line[cnt] == tmp_quote) && (main->line[cnt + 1] != SPACE
					|| main->line[cnt + 1] != DQU || main->line[cnt + 1] != SQU
					|| main->line[cnt + 1] != PIPE || main->line[cnt + 1] != LESS
					|| main->line[cnt + 1] != MORE))
				cnt++;
		}
		new_token = fn_token_new(word, flag, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
	}
	free (word);
	return (cnt);
}