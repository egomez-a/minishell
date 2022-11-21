/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:22:44 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/08 13:12:21 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	dst_len;
	int	src_len;
	int	cnt;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	cnt = 0;
	if ((int)size <= dst_len)
		return (src_len + size);
	while ((dst_len - size--) != 0 && src[cnt++] != 0)
		dst[(dst_len + cnt) - 1] = src[cnt - 1];
	dst[(dst_len + cnt) - 1] = 0;
	return (dst_len + src_len);
}
