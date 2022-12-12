/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:27:46 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 11:38:44 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int				cont;
	int				str;
	unsigned char	*ss1;
	unsigned char	*ss2;

	cont = 0;
	str = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[cont] == ss2[cont] && ss1[cont] != 0 && ss2[cont] != 0)
		cont++;
	str = ss1[cont] - ss2[cont];
	return (str);
}
