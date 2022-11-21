/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 17:22:44 by jcsantos          #+#    #+#             */
/*   Updated: 2021/03/08 13:12:29 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	cnt;
	int	src_len;

	cnt = 0;
	if (src == NULL)
		return (0);
	src_len = ft_strlen((char *)src);
	if ((int)size <= 0)
		return (src_len);
	while (src[cnt] && cnt < (int)(size - 1))
	{
		dst[cnt] = src[cnt];
		cnt++;
	}
	dst[cnt] = '\0';
	cnt = 0;
	return (src_len);
}
