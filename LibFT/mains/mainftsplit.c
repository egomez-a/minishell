/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainftsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 18:01:33 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/09 12:11:59 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_split(char const *s, char c);

int main () 
{
   	int i; 
   	char s[] = ""; 
   	char c = 'n';

   	printf("In the string ------> %s    we need to split the words: %c\n", s, c);
   	printf("The split string is: \n");
   	i = 0; 
   	while (i < 6)
	{
		printf("%s\n", ft_split(s, c)[i]);
		i++;
	}
}