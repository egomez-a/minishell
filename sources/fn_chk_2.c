/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_chk_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:33:01 by juasanto          #+#    #+#             */
/*   Updated: 2023/03/22 17:57:17 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	chk_all(t_main *main, int cnt)
{
	return (main->line[cnt] == PIPE || main->line[cnt] == LESS || \
		main->line[cnt] == MORE || main->line[cnt] == DQU || \
		main->line[cnt] == SQU || main->line[cnt] == DOLLAR);
}

// esta función evalua echo $? debe retornar valor de retorno.
int	chk_dollar_question(t_main *main, int cnt)
{
	t_token		*new_token;

	if (main->line[cnt] == '?' && (main->line[cnt + 1] == SPACE
			|| main->line[cnt + 1] == '\0'))
	{
		write(1, ft_itoa(main->ret), ft_strlen_num(main->ret));
		new_token = fn_token_new(ft_strdup(""), ARG, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		cnt++;
		return (0);
	}
	return (cnt);
}

// esta función evalua si el $ aparece sólo. echo $. 
int	chk_dollar_alone(t_main *main, int cnt)
{
	t_token		*new_token;
	char		*word;
	char		add_one[2];

	word = ft_strdup("");
	add_one[1] = 0;
	if (main->line[cnt] == '\0' || main->line[cnt] == SPACE)
	{
		main->dollaralone = 1;
		add_one[0] = main->line[cnt - 1];
		word = ft_strjoin_clean(word, add_one, 1);
		new_token = fn_token_new(word, ARG, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		free(word);
		return (0);
	}
	return (cnt);
}

int chk_dollar_flag(t_main *main, int cnt)
{
	int flag;
	
	if (main->line[cnt - 1] == SPACE)
		flag = DOLLAR;
	else
	{
		main->dollaralone = 1;
		flag = DOLENC;
	}
	return (flag);
}

int	chk_dollar(t_main *main, int cnt)
{
	t_token		*new_token;
	char		*word;
	char		add_one[2];
	int 		flag;

	word = ft_strdup("");
	add_one[1] = 0;
	if (main->line[cnt] == DOLLAR)
	{
		if (main->line[cnt - 1])
		{
			flag = chk_dollar_flag(main, cnt);
			new_token = fn_token_new("$", flag, 0, 0);
			ft_lstadd_back(&main->commands, ft_lstnew(new_token));
		}
		cnt++;
		if (main->line[cnt] == DQU || main->line[cnt] == SQU
			|| (main->line[cnt] >= '0' && main->line[cnt] <= '9'))
		{
			flag = ARG;
			cnt++;
		}
		if (chk_dollar_alone(main, cnt) == 0)
			return (cnt);
		if (chk_dollar_question(main, cnt) == cnt + 1)
			return (cnt + 1);
		while ((main->line[cnt] != DOLLAR) && (main->line[cnt + 1] != SPACE
				|| main->line[cnt + 1] != DQU || main->line[cnt + 1] != SQU
				|| main->line[cnt + 1] != PIPE || main->line[cnt + 1] != LESS
				|| main->line[cnt + 1] != MORE) && cnt < main->lenght_line)
		{
			add_one[0] = main->line[cnt];
			word = ft_strjoin_clean(word, add_one, 1);
			if (flag != ARG)
				flag = DOLARG;
			cnt++;
			if (main->line[cnt] == DOLLAR || main->line[cnt] == SPACE
				|| main->line[cnt] == DQU || main->line[cnt] == SQU
				|| main->line[cnt] == PIPE || main->line[cnt] == LESS
				|| main->line[cnt] == MORE)
				break ;
		}
		new_token = fn_token_new(word, flag, 0, 0);
		ft_lstadd_back(&main->commands, ft_lstnew(new_token));
	}
	free(word);
	return (cnt);
}

int	chk_dollar_ext(t_main *main)
{
	//TODO: Hacer que chequee que el $ está en la lista de Eugenio, No se
	// como recorrer la lista de Eugenio, ver como la imprime.
	int		ext;
	t_list	*tmp_token;
	t_list	*tmp_env;

	ext = 0;
	tmp_token = main->commands;
	tmp_env = main->envl;
	while (tmp_token != NULL)
	{
		if (((t_token *)tmp_token->content)->type == DOLLAR)
		{
			tmp_token = tmp_token->next;
			while (tmp_env != NULL)
			{
				if (ft_strcmp(((t_token *)tmp_token->content)->word, \
					((t_envel *)tmp_env->content)->name) == 0)
						ext = 1;
				tmp_env = tmp_env->next;
			}

		}
		tmp_token = tmp_token->next;
	}
	return (ext);
}