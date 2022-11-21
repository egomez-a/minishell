/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 10:04:49 by juasanto          #+#    #+#             */
/*   Updated: 2021/02/18 13:39:40 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			cnt;
	unsigned int	ft_len;

	cnt = 0;
	if (s == NULL)
		return (NULL);
	str = ft_calloc(sizeof(*s), (len + 1));
	if (!str)
		return (NULL);
	ft_len = (unsigned int)(ft_strlen(s));
	while (cnt < len && start < ft_len)
	{
		str[cnt] = s[cnt + start];
		cnt++;
	}
	str[cnt] = 0;
	return (str);
}
