/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:22:18 by egomez-a          #+#    #+#             */
/*   Updated: 2022/12/01 11:44:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** In this function we are adding a link, called new, that is passed in our
** parameters, to a list and placing this link at the top of our list.
** First make sure the link passed is not NULL. Then we set our 'new' link
** mext to the first link pointed by alst in our parameters. then we set
** the pointer of alst to new, ie setting it to the head of our linked list
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
