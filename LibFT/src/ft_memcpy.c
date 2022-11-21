/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:43:22 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:10:31 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *str_dst, const void *str_src, size_t str_leng)
{
	unsigned char	*temp_pointer_dest;
	unsigned char	*temp_pointer_src;

	temp_pointer_dest = (unsigned char *)str_dst;
	temp_pointer_src = (unsigned char *)str_src;
	if (!temp_pointer_dest && !temp_pointer_src)
		return (NULL);
	while (str_leng-- != 0)
		*temp_pointer_dest++ = *temp_pointer_src++;
	return (str_dst);
}
