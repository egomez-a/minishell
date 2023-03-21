/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:47:38 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/21 15:34:07 by egomez-a         ###   ########.fr       */
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

int	flag_n_check(char *args)
{
	int	i;
	int	n_flag;

	n_flag = 0;
	if (args && args[0] == '-' && args[1] == 'n')
	{
		i = 2;
		while (args[i] == 'n')
			i++;
		if (args[i] == '\0' || args[i] == ' ')
			n_flag++;
	}
	return (n_flag);
}

// hay que meter los tokens en una matrix, pero diferenciar antes entre los que son
// argumentos y los que son comandos, para que luego podamos buscar los -n
char 	**tokens_into_matrix(t_main *main)
{
	int		i;
	char	**args;
	t_list	*tokens;

	args = (char **)ft_calloc(sizeof(char *), main->lenght_line + 1);
	i = 0;
	tokens = (t_list *)main->commands;
	while (tokens != NULL)
	{
		args[i] = ((t_token *)tokens->content)->word;
		// printf("Token %d es %s\n", i, args[i]);
		i++;
		tokens = tokens->next;
	}
	main->listsize = i;
	// printf("Tamaño de la lista es %d\n", main->listsize);
	return (args);
}

char *checkenvdollar(char **chainwithdollar, t_main main)
{
	printf("%s\n", chainwithdollar);
	
	
}

int	fn_echo(t_main *main, int n_flag)
{
	char	**args;
	t_list	*tokens;
	int 	i;
	int 	j; 

	args = tokens_into_matrix(main);
	i = 0;
	j = 0;
	while (args[i])
	{
		n_flag = n_flag + flag_n_check(args[i]);
		// printf("Arg %d is %s and n_flag is %d\n", i, args[i], n_flag);
		i++;
	}
	i = 0;
	tokens = (t_list *)main->commands;
	while (tokens != NULL)
	{
		if (((t_token *)tokens->content)->type == CMD)
			i++;
		else if (((t_token *)tokens->content)->type == ARG)
		{
			j = i + n_flag;
			ft_putstr_fd(args[j], 1);
			if (j < main->listsize - 1)
				write (1, " ", 1);
			i++;
		}
		else if (((t_token *)tokens->content)->type == DOLLAR)
		{
			((t_token *)tokens->content)->extvar = checkenvdollar(args[i], main);
			args[i] = ((t_token *)tokens->content)->extvar;
			printf("El token es %s\n", args[i]);
			ft_putstr_fd(args[i], 1);
			// if ((ft_strcmp(((t_token *)tokens->content)->word, " ") != 0) || (t_token *)tokens->next != NULL)
			if (j < main->listsize - 1)
				write (1, " ", 1);
			i++;
		}
		tokens = tokens->next;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (0);
}

/* me falta ser capaz de tratar el espacio si pongo echo hola $PWD o echo hola$PWD */