/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:44:09 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/08 13:12:08 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_clean(char *s1, char *s2, int clean)
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strjoin(s1, s2);
	if (clean == 1 || clean == 3)
		free(s1);
	if (clean == 2 || clean == 3)
		free(s2);
	return (tmp);
}
