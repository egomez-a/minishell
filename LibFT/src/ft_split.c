/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juasanto <juasanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 09:12:23 by juasanto          #+#    #+#             */
/*   Updated: 2021/03/15 11:41:06 by juasanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	count_word(char const *str, char chr)
{
	int		swtch;
	int		cnt;

	swtch = 0;
	cnt = 0;
	while (*str != 0)
	{
		if (swtch == 1 && *str == chr)
			swtch = 0;
		if (swtch == 0 && *str != chr)
		{
			swtch = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

int	cnt_pnt_yes(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] == c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

int	cnt_pnt_no(int *cnt_pnt, const char *s, char c)
{
	int	cnt_tmp;

	cnt_tmp = *cnt_pnt;
	while (s[cnt_tmp] != c && s[cnt_tmp] != 0)
		cnt_tmp++;
	return (cnt_tmp);
}

char	**ft_split(char const *s, char c)
{
	int		split_num;
	char	**split_array;
	int		start;
	int		cnt_pnt;
	int		cnt_array;

	cnt_pnt = 0;
	cnt_array = -1;
	if (!s || !c)
		return (NULL);
	split_num = count_word(s, c);
	split_array = (char **)ft_calloc(sizeof(char *), split_num + 1);
	if (!split_array)
		return (NULL);
	while (++cnt_array < split_num)
	{
		cnt_pnt = cnt_pnt_yes(&cnt_pnt, s, c);
		start = cnt_pnt;
		cnt_pnt = cnt_pnt_no(&cnt_pnt, s, c);
		split_array[cnt_array] = ft_substr(s, start, cnt_pnt - start);
		cnt_pnt++;
	}
	split_array[cnt_array] = 0;
	return (split_array);
}
