/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 12:47:12 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:12:54 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	cont;
	int				strncmp;

	cont = 0;
	strncmp = 0;
	if (n == 0)
		return (0);
	while ((str1[cont] == str2[cont]) && \
		str1[cont] && str2[cont] && (cont < n - 1))
		cont++;
	strncmp = ((unsigned char)str1[cont]) - ((unsigned char)str2[cont]);
	return (strncmp);
}
