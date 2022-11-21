/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:41:27 by jcsantos          #+#    #+#             */
/*   Updated: 2021/02/18 12:29:39 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*trgt;

	trgt = malloc(num * size);
	if (!trgt)
		return (NULL);
	ft_bzero(trgt, (num * size));
	return (trgt);
}
