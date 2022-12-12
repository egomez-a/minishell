/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:41:48 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:03:42 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(char *str)
{
	int	signo;
	int	n;

	n = 0;
	signo = 1;
	while ((*str == ' ') || ((*str >= 9) && (*str <= 13)))
		str++;
	if ((*str == '-') || (*str == '+'))
	{
		if (*str == '-')
			signo = -1;
		str++;
	}
	if ((*str == '-') || (*str == '+'))
		return (0);
	while ((*str >= '0') && (*str <= '9'))
	{
		n = n * 10;
		n = n + (int)(*str - 48);
		str++;
	}
	n = n * signo;
	return (n);
}
