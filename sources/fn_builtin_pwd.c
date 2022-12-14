/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:00:20 by egomez-a          #+#    #+#             */
/*   Updated: 2022/05/31 12:01:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		fn_pwd(void)
{
	char	cwd[1024];
	
	if (getcwd(cwd, sizeof(cwd)))
	{
		ft_putendl_fd(cwd, 1);
		return (0);
	}
	else
		return (1);
}
