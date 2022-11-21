/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:16:28 by egomez-a          #+#    #+#             */
/*   Updated: 2022/05/31 12:01:00 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fn_exit(char **args)
{
    int i;
    int j;

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