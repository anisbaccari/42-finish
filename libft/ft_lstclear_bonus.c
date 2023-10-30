/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:34:13 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/24 14:02:18 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/***
 * pour suppri;er les successor tmp = list->next > del lst > ptr = tmp ...
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*ptr;

	if (!lst || !*lst || !del)
		return ;
	ptr = *lst;
	tmp = NULL;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr, (*del));
		ptr = tmp;
	}
	*lst = NULL;
}
