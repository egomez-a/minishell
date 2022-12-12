/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:16:25 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:11:20 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstring(char *putstring)
{
	int	countprint;

	countprint = 0;
	while (putstring[countprint] != 0)
		ft_putchar(putstring[countprint++]);
}
