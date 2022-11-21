/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:40:39 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:18:21 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	if (!n)
		return (0);
	while (n-- != 0)
	{
		if (*(unsigned char *)str1 != *(unsigned char *)str2)
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
		str1++;
		str2++;
	}
	return (0);
}
