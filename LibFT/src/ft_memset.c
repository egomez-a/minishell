/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:17:25 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:10:56 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*temp_pointer;

	temp_pointer = (unsigned char *)s;
	while (n-- > 0)
		*temp_pointer++ = c;
	return (s);
}
