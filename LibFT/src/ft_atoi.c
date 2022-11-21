/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:08:02 by jcsantos          #+#    #+#             */
/*   Updated: 2022/04/14 11:28:37 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	ft_atoi(const char *str)
{
	int						sign;
	long long int			result;

	result = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit((int)*str))
	{
		if (result < 9223372036854775807)
		{
			result = result * 10 + *str - '0';
			str++;
		}
		else
			return ((sign - 1) * 1);
	}
	if (sign == 1)
		return (-result);
	return (result);
}
