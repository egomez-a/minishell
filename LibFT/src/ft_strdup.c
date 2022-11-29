/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 09:48:27 by juasanto          #+#    #+#             */
/*   Updated: 2022/11/29 11:56:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*trgt;

	trgt = ft_calloc(sizeof(*str), (ft_strlen((char *)str)) + 1);
	if (trgt)
		trgt = ft_strcpy(trgt, (char *)str);
	return (trgt);
}
