/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:26:17 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/12 10:12:51 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Reserva memoria con malloc y devuelve la cadena de caracteres que es copia
** de 's1', sin los caracteres indicados en 'set' al principio y al final de la
** cadena de caracteres. NULL si falla la reserva de memoria.
** Uso la funcion ft_strchr, que busca el caracter s1[beg] en set, con un
** contador beg que se para cuando s1 termina. Por tanto retorna la posicion beg
** que es donde esta el carácter buscado.
*/

size_t	ft_begtrim(char const *s1, char const *set)
{
	int	beg;

	beg = 0;
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	return (beg);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	beg = ft_begtrim(s1, set);
	end = ft_strlen(s1);
	if (beg == end)
	{
		str = malloc(sizeof(char *));
		str[0] = '\0';
		return (str);
	}
	while (s1[end - 1] != '\0' && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - beg + 1));
	if (!(str))
		return (NULL);
	i = 0;
	while (beg < end)
		str[i++] = s1[beg++];
	str[i] = '\0';
	return (str);
}
