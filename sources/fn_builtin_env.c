/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:15:56 by egomez-a          #+#    #+#             */
/*   Updated: 2022/11/17 10:14:45 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 
** imprime los nombres de variables de entorno "=" las variables
** Si no hay variables de entorno tienen que estar las mínimas que son PWD y SHLVL
*/

/*  Esto es muy util para ver el casteo de las variables */

void	print_envlist(t_list *list)
{
	int i;

	i = 1;	
	printf("Numero elementos es %d\n", ft_lstsize(list));
	while (list != NULL)
	{
		printf("%d Nombre: %s\n", i, ((t_envel *)list->content)->name);
		printf("%d Valor :  %s\n", i, ((t_envel *)list->content)->value);
		i++;
		list = list->next;
	}
}

// Estas funciones buscan los valores que hay en PATH y los mete en una matriz que me sirva luego para 
// añadir al primer comando y comprobar si es ejecutable. 
char	**paths_with_separator(char *paths)
{
	char	**matrixpaths;
	char	**matrixwithseparator;
	int		i;

	matrixpaths = ft_split(paths, ':');
	i = 0;
	matrixwithseparator = ft_calloc(ft_matrixlen(matrixpaths) + 2, sizeof(char *));
	i = 0;
	while (i < ft_matrixlen(matrixpaths))
	{
		matrixwithseparator[i] = ft_strjoin(matrixpaths[i], "/");
		i++;
	}
	matrixwithseparator[i + 1] = NULL;
	free(paths);
	free(matrixpaths);
	return (matrixwithseparator);
}

char	**paths_from_env(t_main *main)
{
	char	*paths;
	char	*aux;
	t_list	*list;
	char	**matrix;
	
	
	list = main->envl;
	while (list != NULL)
	{
		if (ft_strcmp((((t_envel *)list->content)->name), "PATH") == 0)
			paths = ((t_envel *)list->content)->value;
		list = list->next;
	}
	matrix = paths_with_separator(paths);
	return (matrix);
}

int		fn_env(t_main   *main)
{
	t_list	*list;

	list = main->envl;
    while (list != NULL)
	{
		printf("%s", ((t_envel *)list->content)->name);
        printf("=");
		printf("%s\n", ((t_envel *)list->content)->value);
		list = list->next;
	}
	return (0);
}
