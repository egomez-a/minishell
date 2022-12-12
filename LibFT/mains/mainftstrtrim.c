/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainftstrtrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:26:34 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/05 19:11:27 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set);

int 	main(void)
{
	char set [] = "\t \n";
	char s1[] = "          ";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
