/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:17:44 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/09 16:19:26 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_array(char **str)
{
	int	cnt;

	cnt = 0;
	if (!str)
		return ;
	while (str[cnt])
	{
		free(str[cnt]);
		str[cnt++] = NULL;
	}
	free(str);
	str = NULL;
}
