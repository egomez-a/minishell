/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:38:38 by egomez-a          #+#    #+#             */
/*   Updated: 2022/11/21 14:09:35 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int    ft_strlen_num(int num)
{
    int     len;

    len = 0;
    if (num <= 0)
        len = 1;
    while (num != 0)
    {
        len++;
        num = num / 10;
    }
    return (len);
}
