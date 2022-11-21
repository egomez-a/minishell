/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcsantos <jcsantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:26:18 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/13 11:44:13 by jcsantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	cnt_char(long int n)
{
	long int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char			*dest;
	int				len;
	unsigned int	tmp;
	int				cnt;

	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	len = cnt_char(n);
	dest = malloc(len + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	if (n < 0)
		dest[0] = '-';
	cnt = len - 1;
	while (tmp >= 10)
	{
		dest[cnt] = tmp % 10 + 48;
		tmp /= 10;
		cnt--;
	}
	dest[cnt] = tmp % 10 + 48;
	dest[len] = '\0';
	return (dest);
}
