/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:35 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/27 12:01:32 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char    *update_oldpwd(t_main *main)
{
    char    dir_temp[1024];

    main->env_path = ft_strdup(getcwd(dir_temp, 1024));
    main->temp_oldpwd = ft_strdup(main->temp_pwd);
    main->temp_pwd = ft_strdup(main->env_path);
    return (main->env_path);         
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
    printf("Status de las variables \n");
    printf("main env path actual %s\n", main->env_path);
    printf("main oldpwd actual %s\n", main->temp_oldpwd);
    printf("main temp_pwd actual %s\n", main->temp_pwd);
    main->env_path = ft_strdup(main->home);
    main->temp_oldpwd = ft_strdup(main->temp_pwd);
    main->temp_pwd = ft_strdup(main->env_path);
    printf("Si pongo 'cd' Directorio nuevo es %s, oldpwd es %s\n", main->env_path,  main->temp_oldpwd);
    return (0);
}

int 	fn_cd(t_main *main)
{
	char	**arguments;
    int     cd_return;
    int     i;
    char    dir_temp[1024];

    main->env_path = ft_strdup(getcwd(dir_temp, 1024));
    printf("el env_path es %s\n", main->env_path);
	arguments = ft_split(main->line, ' '); // tengo que ver el caso donde haya varios espacios seguidos
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
        cd_return = ft_cd_alone(main);
    // caso cd -, debe ir al OLDPWD
    else if (arguments[1] && !ft_strcmp(arguments[1], "-"))
    {
        printf("Analizo cd -\n");
        cd_return = chdir(main->temp_oldpwd);
        printf("El nuevo directorio es %s\n", main->temp_oldpwd);
        main->env_path = update_oldpwd(main);
        printf("Si pongo 'cd -' Directorio nuevo es %s, oldpwd es %s\n", main->env_path,  main->temp_oldpwd);
    }
    //  caso cd 'lo que sea'
    else if (arguments[1])
    {
        if (!opendir(arguments[1]))
        {
            printf("El Argumento %s no existe\n", arguments[1]);
            ft_free_array(arguments);
            return (1);
        }
        cd_return = chdir(arguments[1]);
        main->env_path = update_oldpwd(main);
        printf("Si pongo 'cd ..' Directorio nuevo es %s, oldpwd es %s\n", main->env_path,  main->temp_oldpwd);
    }
    ft_free_array(arguments);
    printf("la variable cd_return es %d\n", cd_return);
    return (cd_return);
}
