/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:23:23 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:46:52 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		len;
	int		i;

	len = 0;
	ch = (char)c;
	while (s[len] != '\0')
		len++;
	if (c == 0)
		return ((char *)s + len);
	i = len;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
