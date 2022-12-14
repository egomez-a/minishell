/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:22:52 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/14 17:00:31 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* 
** Saca los nombres de variables de entorno y las variables y las mete en lista 
** enlazada. Si no hay variables de entorno (porque ponen env -i ./minishell
** tienen que estar las mínimas que son PWD y SHLVL
*/

t_envel	*fn_enve_new(char *envi, char *string)
{
	t_envel		*temp;

	temp = ft_calloc(sizeof(t_envel), 1);
	temp->value = ft_strtrim(string, "=");
	temp->name = ft_substr(envi, 0, (ft_strlen(envi) - ft_strlen(temp->value)
				- 1));
	return (temp);
}

char	**fn_myenv(void)
{
	char	cwd[1024];
	char	**temp;

	temp = ft_calloc(3, sizeof(char *));
	temp[0] = ft_strjoin("PWD=", getcwd(cwd, sizeof(cwd)));
	temp[1] = ft_strdup("SHLVL=1");
	temp[2] = NULL;
	return (temp);
}

void	ft_env_list(t_main *main, char **env)
{
	char	*string;
	t_envel	*envlist;
	int		i;

	if (!*env)
	{
		env = fn_myenv();
		main->control = 1;
	}
	i = 0;
	while (env[i])
	{
		string = ft_strchr(env[i], '=');
		envlist = fn_enve_new(env[i], string);
		ft_lstadd_back(&main->envl, ft_lstnew(envlist));
		i++;
	}
	if (main->control == 1)
		ft_free_array(env);
}
