/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:55:25 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:46:19 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** strdup allocates sufficient memory for a copy of the string s1, does the
** copy, and returns a pointer to it.  The pointer may subsequently be used as
** an argument to the function free(3). If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

char		*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*ptr;

	len = 0;
	while (s1[len])
		len++;
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
