/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:29:00 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/24 13:03:37 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*new;

	if (!lst || !*f || !*del)
		return (NULL);
	header = ft_lstnew(f(lst->content));
	if (!header)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
		{
			ft_lstclear(&header, del);
			return (NULL);
		}
		ft_lstadd_back(&header, new);
		lst = lst->next;
	}
	return (header);
}
