/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:47:50 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/20 14:49:32 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrixdup(char **array)
{
	int		i;
	char	**matrix;

	i = 0;
	matrix = malloc(sizeof(char *) * (ft_matrixlen(array) + 1));
	while (array[i])
	{
		matrix[i] = ft_strdup(array[i]);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
