/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_utilist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:48:55 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 13:14:48 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Para liberar el contenido de la lista enlazada y evitar los problemas de leaks */

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
	if ((((t_token *)list->content)->type) != RD
		|| (((t_token *)list->content)->type) != APPEND
		|| (((t_token *)list->content)->type) != HERE)
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
