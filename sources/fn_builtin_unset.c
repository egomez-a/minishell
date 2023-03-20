/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:15:17 by egomez-a          #+#    #+#             */
/*   Updated: 2023/03/20 20:57:47 by alfgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fn_unset(t_main *main)
{
    t_list  *list;
    t_list  *ant;
    char    *var_to_unset;

    list = main->envl;
    var_to_unset = ((t_token *)main->commands->next->content)->word;
    ant = list;
	while (list != NULL && ((t_envel *)list->content)->name != NULL)
    {
        if (ft_strcmp(((t_envel *)list->content)->name, var_to_unset) == 0)
        {
            ft_free_envel(list->content);
            ant->next = list->next;
            break ;
        }
        else
        {
            ant = list;
            list = list->next;
        }
    }
    return (0);
}
