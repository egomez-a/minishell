/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:21:54 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:46:06 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** The strchr() function locates the first occurrence of c (converted to a char)
** in the string pointed to by s. The terminating null character is considered
** to be part of the string; therefore if c is `\0', the functions locate the
** terminating `\0'. Returns a pointer to the located character, or NULL if the
** character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
		len++;
	while (i <= len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	return (NULL);
}
