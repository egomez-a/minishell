/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:47:38 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/14 18:56:32 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* 
** echo [options] [texto]. Sólo hay que hacer -n que omite un salto de linea. 
** hay que tener en cuenta -n -n -n equivale a -n y -n -nnnn equivale a -n
** Si el número de argumentos es mayor que 1, entonces comparo con ft_strcmp 
** para ver si existe el flag -n. Si no se añade este flag, el flag n_flag es 0
** Por último hay que cambiar desde char **args a lo que vaya a ser la entrada
*/

static int	number_of_arguments(char **args)
{
	int		i;

	i = 0;
	while (args[i])
	{
		printf("args %d  --- %s\n", i, args[i]);
		i++;
	}
	return (i);
}

/* 
** he usado chatgpt para optimizar mi función, y en efecto la hace más concisa 
** y legible.
*/

int	flag_treatment(char **args)
{
	int	num_args;
	int	i;
	int	j;
	int	n_flag;

	num_args = number_of_arguments(args);
	if (num_args == 0 || !args || !args[0])
		return (-1);
	i = 0;
	n_flag = 0;
	while (i < num_args)
	{
		if (args[i] && args[i][0] == '-' && args[i][1] == 'n')
		{
			j = 2;
			while (args[i][j] == 'n')
				j++;
			if (args[i][j] == '\0' || args[i][j] == ' ')
				n_flag++;
		}
		i++;
	}
	return (n_flag);
}

int	flag_treatment2(char **args)
{
	int	i;
	int	j;
	int	n_flag;
	int	num_args;

	n_flag = 0;
	num_args = number_of_arguments(args);
	i = 0;
	if (num_args > 1 && args[1][0] == '-' && args[1][1] == 'n')
	{
		while (i < num_args)
		{
			if (args[i] && args[i][0] == '-' && args[i][1] == 'n')
			{
				j = 2;
				if (args[i][j] == '\0' || args[i][j] == ' ')
					n_flag++;
				else if (args[i][j] == 'n')
				{
					while (args[i][j] == 'n')
						j++;
					if (args[i][j] != 'n')
					{
						if (args[i][j] == '\0' || args[i][j] == ' ')
							n_flag++;
						else
							break ;
					}
				}
			}
			i++;
		}
	}
	return (n_flag);
}

char		*checkenvdollar(char *vardollar, t_main *main)
{
	t_list	*list;
	char 	*aux;
	
	list = main->envl;
	while (list->next != NULL)
	{
		if (ft_strncmp(vardollar, (((t_envel *)list->content)->name), ft_strlen(vardollar)) == 0)
		{
			// printf("la variable %s", vardollar);
			aux = ft_strdup(((t_envel *)list->content)->value);
			// printf("  va a tomar el valor %s\n", aux);
		}
		list = list->next;
	}
	return (aux);	
}

int	fn_echo(t_main *main)
{
	int		i;
	int		n_flag;
	char	**args;
	t_list	*tokens;

	args = (char **)ft_calloc(sizeof(char *), main->lenght_line + 1);
	i = 0;
	n_flag = 0;
	tokens = (t_list *)main->commands;
	while (tokens != NULL)
	{
		n_flag = flag_treatment(args);
		if (((t_token *)tokens->content)->type == CMD)
			args[i] = NULL;
		else if (((t_token *)tokens->content)->type == ARG)
		{
			args[i] = ((t_token *)tokens->content)->word;
			ft_putstr_fd(args[i], 1);
			if ((t_token *)tokens->next != NULL &&
				(((t_token *)tokens->next->content)->type != DOLENC
					|| ((t_token *)tokens->next->content)->type != DOLLAR))
				write (1, " ", 1);
		}
		else if (((t_token *)tokens->content)->type == DOLLAR
			|| ((t_token *)tokens->content)->type == DOLENC)
		{
			args[i] = (((t_token *)tokens->content)->word);
			((t_token *)tokens->content)->extvar = checkenvdollar(args[i], main);
			args[i] = ((t_token *)tokens->content)->extvar;
			ft_putstr_fd(args[i], 1);
			if (ft_strcmp(((t_token *)tokens->content)->word, " ") != 0 || ((t_token *)tokens->content)->type != DOLENC)
				write (1, " ", 1);
		}
		i++;
		tokens = tokens->next;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (0);
}

/* me falta ser capaz de tratar el espacio si pongo echo hola $PWD o echo hola$PWD */