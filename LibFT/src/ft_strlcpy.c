/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:06:23 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:10:33 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** strlcpy() takes the full size of the destination buffer and guarantees
** NUL-termination if there is room.  Room for the NUL should be included in
** dstsize. Returns size of src, the string it tried to create.
** strlcpy() copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	lensrc;

	if (!src || !dest)
		return (0);
	lensrc = 0;
	while (src[lensrc])
		lensrc++;
	j = 0;
	if (size > 0)
	{
		while (src[j] != '\0' && j < size - 1)
		{
			dest[j] = src[j];
			j++;
		}
		if (j < size)
			dest[j] = '\0';
	}
	return (lensrc);
}
