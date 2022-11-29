/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utilist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:48:55 by egomez-a          #+#    #+#             */
/*   Updated: 2022/11/29 15:20:54 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Para liberar el contenido de la lista enlazada y evitar los problemas de leaks */

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

char	**args_list_into_matrix(t_main *main)
{
	int		i;
	char	**args;
	t_list	*tokens;

	args = (char **)ft_calloc(sizeof(char *), main->lenght_line + 1);
	i = 0;
	tokens = (t_list *)main->commands;
	while ((tokens != NULL) && ((t_token *)tokens->content)->type == ARG)
	{
		args[i] = ((t_token *)tokens->content)->word;
		i++;
		tokens = tokens->next;
	}
	return (args);
}

void	print_list(t_list *list)
{
	printf("Numero tokens: %i\n", ft_lstsize(list));
	while (list != NULL)
	{
		printf("Word: %s\t\t", ((t_token *)list->content)->word);
		printf("Type: %i\t\n", ((t_token *)list->content)->type);
		// printf("extvar: %s\t", ((t_token *)list->content)->extvar);
		// printf("FD: %i\t", ((t_token *)list->content)->fd);
		// printf("Quote: %i\n", ((t_token *)list->content)->quote);
		list = list->next;
	}
}

void	first_token_cmd(t_list *list)
{
	if ((((t_token *)list->content)->type) != RD ||
		(((t_token *)list->content)->type) != APPEND ||
		(((t_token *)list->content)->type) != HERE)
	{
		(((t_token *)list->content)->type) = CMD;
	}
	list = list->next;
	while (list != NULL)
	{
		if ((((t_token *)list->content)->type) == PIPE)
		{
			list = list->next;
			(((t_token *)list->content)->type) = CMD;
		}
		list = list->next;
	}
}
