/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:43:16 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/17 19:02:52 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * ajouter avant lst , si lst n est pas vide on fait new.next = lst pour mettre
 * next devant lst
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst == NULL)
		*lst = new;
	else if (lst)
	{
		new->next = *lst;
		*lst = new;
	}	
}
