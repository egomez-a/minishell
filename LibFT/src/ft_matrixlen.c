/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:54:14 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:06:17 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_matrixlen(char **matrix)
{
	int	i;

	if (!matrix)
		return (0);
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
