/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:12:44 by juasanto          #+#    #+#             */
/*   Updated: 2022/12/12 14:14:50 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*fn_token_new(char *word, int type, int fd, int quo)
{
	t_token		*temp;

	temp = ft_calloc(sizeof(t_token), 1);
	temp->word = ft_strdup(word);
	temp->extvar = NULL;
	temp->type = type;
	temp->fd = fd;
	temp->quote = quo;
	return (temp);
}

int		word_nam(t_main *main, int type, int separator, int cnt)
{
	int			cnt1;
	char		*word;
	char		add_one[2];
	int			end_quo;
	t_token		*new_token;

	cnt1 = cnt;
	add_one[1] = 0;
	new_token = NULL;
	end_quo = 0;
	word = ft_strdup("");
	while (main->line[cnt] != separator && cnt < main->lenght_line)
	{
		if ((main->line[cnt] == DQU || main->line[cnt] == SQU)
			&& main->line[cnt - 1] != SPACE)
		{
			end_quo++;
			cnt++;
		}
		if (end_quo == 2 || (chk_all(main, cnt) == 1
				&& (separator != DQU && separator != SQU)))
			break ;
		add_one[0] = main->line[cnt];
		word = ft_strjoin_clean(word, add_one, 1);
		cnt++;
	}
	if ((cnt != cnt1) && end_quo != 1)
	{
		new_token = fn_token_new(word, type, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
	}
	free (word);
	return (cnt - cnt1);
}

t_token	*fn_token_list(t_main *main)
{
	int		cnt;
	int		type;

	cnt = 0;
	type = ARG;
	// printf("Line: %s\n", main->line);
	while (main->line[cnt] != 0 && cnt < main->lenght_line)
	{
		if (main->line[cnt] == SPACE)
			cnt++;
		else
		{
			cnt = chk_here(main, cnt);
			cnt = chk_redirect(main, cnt);
			cnt = chk_pipe(main, cnt);
			cnt = chk_quote(main, cnt);
			cnt = chk_dollar(main, cnt);
			if (cnt < main->lenght_line && main->line[cnt] != DOLLAR)
			{
				cnt = cnt + word_nam(main, type, SPACE, cnt);
				type = ARG;
			}		
		}
	}
	return (main->tokens);
}
