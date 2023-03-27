/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:35 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/27 13:59:44 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *update_oldpwd(t_main *main)
{
	char    dir_temp[1024];
	char	*path;

	path = ft_strdup(getcwd(dir_temp, 1024));
	main->temp_oldpwd = ft_strdup(main->temp_pwd);
	main->temp_pwd = ft_strdup(path);
	free(path);
	return (main->temp_pwd);         
}

void    update_key_envvariables(t_main *main)
{
	t_list  *list;

	list = main->envl;
	while (list != NULL)
	{
		if (ft_strcmp((((t_envel *)list->content)->name),"OLDPWD") == 0)
			((t_envel *)list->content)->value =  ft_strdup(main->temp_oldpwd);
		if (ft_strcmp((((t_envel *)list->content)->name), "PWD") == 0)
			((t_envel *)list->content)->value = ft_strdup(main->temp_pwd);
		list = list->next;
	}
}

void    key_envvariables(t_main *main)
{
	t_list  *list;
	
	list = main->envl;
	while (list != NULL)
	{
		if (ft_strcmp((((t_envel *)list->content)->name), "HOME") == 0)
			main->home = ft_strdup(((t_envel *)list->content)->value);
		if (ft_strcmp((((t_envel *)list->content)->name),"OLDPWD") == 0)
			main->temp_oldpwd = ft_strdup(((t_envel *)list->content)->value);
		if (ft_strcmp((((t_envel *)list->content)->name), "PWD") == 0)
			main->temp_pwd = ft_strdup(((t_envel *)list->content)->value);
		list = list->next;
	}
	return ;
}

// caso cd 'a secas', sin argumentos
int     ft_cd_alone(t_main *main)
{
	if (!main->home)
	{
		write(2, "minishell: cd: HOME not set\n", ft_strlen("minishell: cd: HOME not set\n"));
		return (1);
	}
	main->temp_oldpwd = ft_strdup(main->temp_pwd);
	free(main->temp_pwd);
	main->temp_pwd = ft_strdup(main->home);
	chdir(main->temp_pwd);
	printf("Si pongo 'cd' Directorio nuevo es %s, oldpwd es %s\n", main->temp_pwd,  main->temp_oldpwd);
	return (0);
}

// caso 'cd -' debe ir a OLDPWD
int		ft_cd_guion(t_main *main)
{
	char *tmp;
	
	tmp = NULL;
	if (!main->temp_oldpwd)
	{
		write(2, "minishell: cd: OLDPWD not set\n", ft_strlen("minishell: cd: OLDPWD not set\n"));
		return (1);
	}
	tmp = ft_strdup(main->temp_pwd);
	free(main->temp_pwd);
	main->temp_pwd = ft_strdup(main->temp_oldpwd);
	main->temp_oldpwd = ft_strdup(tmp);
	free(tmp);
	chdir(main->temp_pwd);
	printf("Si pongo 'cd -' Directorio nuevo es %s \t\t oldpwd es %s\n", main->temp_pwd,  main->temp_oldpwd);
	return (0);
}

// caso cd path 
int		ft_cd_path(t_main *main, char *route)
{
	char tmp[1024];
	
	if (open(route, O_RDONLY) < 0)
	{
		write(2, "minishell: cd: ", ft_strlen("minishell: cd: "));
		write(2, route, ft_strlen(route));
		write(2, ": No such file or directory\n", ft_strlen(": No such file or directory\n"));
		return (1);
	}
	main->temp_oldpwd = ft_strdup(main->temp_pwd);
	chdir(route);
	getcwd(tmp, 1024);
	free(main->temp_pwd);
	main->temp_pwd =ft_strdup(tmp);
	return (0);
}

int	ft_check_cd(char *directory)
{
	DIR		*dire;

	dire = opendir(directory);
	if (!dire)
	{
		perror ("minishell");
		return (1);
	}
	closedir(dire);
	return (0);
}

char	*ft_path_suffix(char *path, char *suffix)
{
	char *s1;
	char *s2;

	s1 = ft_strjoin(path, "/");
	s2 = ft_strjoin(s1, suffix);
	free(s1);
	return(s2);
}

int 	fn_cd(t_main *main)
{
	char	**arguments;
	char 	*route;
	int     i;

	arguments = ft_split(main->line, ' '); // tengo que ver el caso donde haya varios espacios seguidos
	i = 0;
	while (arguments[i])
	{
		printf("argument %d is %s\n", i, arguments[i]);
		i++;
	}
	key_envvariables(main);
	if (!arguments[1] || !ft_strcmp(arguments[1], "~"))
		main->ret = ft_cd_alone(main);
	else if (arguments[1] && !ft_strcmp(arguments[1], "-"))
		main->ret = ft_cd_guion(main);
	else if (arguments[1])
	{
		if (*arguments[1] == '/')
			route = ft_strdup(arguments[1]);
		else
			route = ft_path_suffix(main->temp_pwd, arguments[1]);
		if (ft_check_cd(route) == 1)
		{
			free(main->temp_pwd);
			return (1);
		}
		main->ret = ft_cd_path(main, route);
		free(route);
	}
	update_key_envvariables(main);
	ft_free_array(arguments);
	printf("la variable cd_return es %d\n", main->ret);
	return (main->ret);
}
