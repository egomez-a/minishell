/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:35 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/20 11:06:11 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *update_oldpwd(t_main *main)
{
    char    dir_temp[1024];
    char    *env_path;

    env_path = ft_strdup(getcwd(dir_temp, 1024));
    main->temp_oldpwd = ft_strdup(main->temp_pwd);
    main->temp_pwd = ft_strdup(env_path);
    return (env_path);         
}

void    key_envvariables(t_main *main)
{
    t_list  *list;
    
    list = main->envl;
    while (list != NULL)
	{
		if (!ft_strcmp((((t_envel *)list->content)->name), "HOME"))
            main->home = ft_strdup(((t_envel *)list->content)->value);
		if (!ft_strcmp((((t_envel *)list->content)->name),"OLDPWD"))
			main->temp_oldpwd = ft_strdup(((t_envel *)list->content)->value);
        if (!ft_strcmp((((t_envel *)list->content)->name), "PWD"))
            main->temp_pwd = ft_strdup(((t_envel *)list->content)->value);
        list = list->next;
	}
}

int 	fn_cd(t_main *main)
{
	char	**arguments;
	char	*test_echo;
    int     cd_return;
    char    *env_path;
    int     i;

    // tengo que sustituir todo esto por los argumentos que vengan de la tokenización 
    test_echo = "CD /sources";
	arguments = ft_split(test_echo, ' ');
    i = 0;
    while (arguments[i])
    {
        printf("argument %d is %s\n", i, arguments[i]);
        i++;
    }
    key_envvariables(main);
    cd_return = 0;
    // caso cd 'a secas', sin argumentos
    if (!arguments[1] || !ft_strcmp(arguments[1], "~"))
    {
        printf("Analizo cd\n");
        env_path = ft_strdup(main->home);
        printf("Si pongo 'cd' Directorio nuevo es %s, oldpwd es %s\n", env_path,  main->temp_oldpwd);
        cd_return = 0;
    }
    // caso cd -, debe ir al OLDPWD
    else if (arguments[1] && !ft_strcmp(arguments[1], "-"))
    {
        printf("Analizo cd -\n");
        cd_return = chdir(main->temp_oldpwd);
        printf("El nuevo directorio es %s\n", main->temp_oldpwd);
        env_path = update_oldpwd(main);
        printf("Si pongo 'cd -' Directorio nuevo es %s, oldpwd es %s\n", env_path,  main->temp_oldpwd);
    }
    //  caso cd 'lo que sea'
    else if (arguments[1])
    {
        if (!opendir(arguments[1]))
        {
            printf("El Argumento %s no existe\n", arguments[1]);
            return (1);
        }
        cd_return = chdir(arguments[1]);
        env_path = update_oldpwd(main);
        printf("Si pongo 'cd ..' Directorio nuevo es %s, oldpwd es %s\n", env_path,  main->temp_oldpwd);
    }
    ft_free_array(arguments);
    printf("la variable cd_return es %d\n", cd_return);
    return (cd_return);
}
