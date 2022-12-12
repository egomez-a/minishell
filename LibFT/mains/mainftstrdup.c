/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainftstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:55 by jtoty             #+#    #+#             */
/*   Updated: 2021/02/03 19:16:20 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int				main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	char	*str_dup;

	if (!(str_dup = ft_strdup(str)))
		ft_print_result("NULL");
	else
		ft_print_result(str_dup);
	if (str_dup == str)
		ft_print_result("\nstr_dup's adress == str's adress");
	else
		free(str_dup);
	return (0);
}
