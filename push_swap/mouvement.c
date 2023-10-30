/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:16:09 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 13:06:32 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_sx_move(t_stack **a)
{
	int			tmp;
	t_stack		*first;

	first = *a;
	tmp = (*a)->n;
	(*a)->n = (*a)->next->n;
	(*a)->next->n = tmp;
	*a = first;
	return ;
}

void	ft_rx_move(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	last = NULL;
	if (a && *a)
	{
		first = *a;
		second = first->next;
		while ((*a)->next)
			*a = (*a)->next;
		last = *a;
		last->next = first;
		*a = second;
		first->next = NULL;
	}
	return ;
}

void	ft_rrx(t_stack **a)
{
	t_stack	*first;
	t_stack	*before_last;
	t_stack	*last;
	int		i;

	last = NULL;
	i = stack_size(a) - 2;
	if (a && *a)
	{
		first = *a;
		while (i != 0)
		{
			*a = (*a)->next;
			i--;
		}
		before_last = *a;
		last = (*a)->next;
		last->next = first;
		*a = last;
		before_last->next = NULL;
	}
}
