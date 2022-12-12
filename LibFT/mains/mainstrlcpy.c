/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstrlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:56:52 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/05 12:56:45 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *scr, unsigned int size);

int	main(void)
{
	char src[] = "1234";
	char dest[] = "933233"; 
	unsigned int size = 6;

	printf("Cadena src  -- %s\n", src);
	printf("Cadena dst -- %s\n", dest);
	printf("Size -- %d\n\n", size);

    ft_strlcpy(dest, src, size);
	printf("Cadena dst con ft_strlcpy -- %s\n", dest);
	printf("Retorno de mi funcion %d\n\n", ft_strlcpy(dest, src, size));	
	
	char src2[] = "1234";
	char dest2[] = "933323"; 
	unsigned int size2 = 6;
	strlcpy(dest2, src2, size2); 
	printf("Cadena dst2 con strlcpy -- %s\n", dest2);
	printf("retorno de strlcpy -- %lu\n", strlcpy(dest2, src2, size2));

	return (0);
}

