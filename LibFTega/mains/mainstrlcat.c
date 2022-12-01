/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstrlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 09:49:25 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/03 19:44:36 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char src[] = "12";
	char dest[20] = "abcdefg";
	char dest2[20] = "ABCDEFG"; 

	printf("Cadena dest -- %s\n", dest);
	printf("Cadena src -- %s\n", src);
	printf("size -- %d\n", 6); 

	printf("Resultado con strlcat -- %lu\n", strlcat(src, dest, 5));
	printf("cadena dst nueva %s\n", dest);
	printf("Resultado con ft_strlcat-- %u\n", ft_strlcat(src, dest2, 6));
	
	return (0);
}
