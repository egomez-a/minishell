/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:32:05 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:10:21 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** strlcat() takes the full size of the destination buffer and guarantees
** NUL-termination if there is room.  Room for the NUL should be included in
** dstsize. Returns size of src, the string it tried to create.
** strlcat() appends string src to the end of dst.  It will append at most
** dstsize -strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string). The function returns the lenght of the string
** it is trying to create: lenght of src plus initial lenght of dst
*/

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	lensrc;
	unsigned int	lendst;
	unsigned int	i;

	lensrc = 0;
	lendst = 0;
	while (src[lensrc])
		lensrc++;
	if (size == 0)
		return (lensrc);
	while (lendst < size && dest[lendst])
		lendst++;
	if (size <= lendst)
		return (size + lensrc);
	i = 0;
	while ((src[i]) && ((lendst + i + 1) < size))
	{
		dest[i + lendst] = src[i];
		i++;
	}
	if (lendst != size)
		dest[lendst + i] = '\0';
	return (lendst + lensrc);
}
