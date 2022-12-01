/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainftatoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:59:04 by egomez-a          #+#    #+#             */
/*   Updated: 2021/02/05 20:10:35 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(void)
{
	char *str="+-48";
	printf("cadena str --> %s\n", str);
	printf("atoi -----> %d\n", atoi(str));
	printf("ft_atoi --> %d\n", ft_atoi(str));
}
