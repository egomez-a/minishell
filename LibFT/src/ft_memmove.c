/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:58:48 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:10:49 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *str_ds, const void *str_src, size_t num_c)
{
	int	cnt;

	if ((!str_ds && !str_src) || num_c == 0)
		return (str_ds);
	if (str_ds > str_src)
	{
		cnt = (int)num_c - 1;
		while (cnt >= 0)
		{
			*(char *)(str_ds + cnt) = *(char *)(str_src + cnt);
			cnt--;
		}
	}
	else
	{
		cnt = 0;
		while (cnt < (int)num_c)
		{
			*(char *)(str_ds + cnt) = *(char *)(str_src + cnt);
			cnt++;
		}
	}
	return (str_ds);
}
