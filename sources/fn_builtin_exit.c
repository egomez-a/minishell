/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:16:28 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/18 23:47:28 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int is_strnum(char *str)
{
    int i;

    i = -1;
    while (str[++i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
    }
    return (1); 
}

int		fn_exit(t_main *main)
{

    printf("Numero de token: %d\n", ft_lstsize(main->commands));
    printf("Primer token: %s\n", ((t_token *)main->commands->content)->word);
    main->ex = 1;
    if (ft_lstsize(main->commands) > 2)
    {   
        printf("minishell: exit: too many arguments\n");
        main->ex = 0;
        return (1);
    }
    else if (ft_lstsize(main->commands) == 2 && !is_strnum(((t_token *)main->commands->next->content)->word)) //tam 2 y arr[2] no num
    {
        printf("minishell: exit: %s: numeric argument requiered\n", ((t_token *)main->commands->next->content)->word);
        return (255);
    }
    else if (ft_lstsize(main->commands) == 2)
        return (ft_atoi(((t_token *)main->commands->next->content)->word));
    else
        return (0);
}

// main->commands es un t_list con los términos de entrada. 
// Pruebas en bash con exit y varios comandos (cuando sale echo $?)
// Si escribo exit --> sale y exitcode es 0
// Si escribo exit 33 --> sale y exitcode es 33
// Si escribo exit 1 --> sale y exitcode es 1
// Si escribo exit 256 --> sale y exitcode es 0
// Si escribo exit 257 --> sale y exitcode es 1
// Si escribo exit 33 45 -> NO Sale y escribe bash:exit: too many arguments
// Si escribo exit hfh --> sale y escribe bash: exit: fds: numeric argument required, 
//                          y luego exitcode 255
