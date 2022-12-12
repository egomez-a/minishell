/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:29:34 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:30:04 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbpos;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbpos = n * (-1);
	}
	else
		nbpos = (unsigned int)n;
	if (nbpos >= 10)
	{
		ft_putnbr_fd(nbpos / 10, fd);
		ft_putnbr_fd(nbpos % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbpos, fd);
}
