/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:31:29 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:47:01 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Reserva memoria con malloc y devuelve una nueva cadena de caracteres que
** proviene de la cadena 's' pasada como argumento. Esta nueva cadena comieza
** en el índice 'start' y tiene como tamaño máximo 'len'.
** para ello recorro la cadena origina con el contador 'i' hasta llegar a la
** posicion 'start y luego hasta 'len'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
