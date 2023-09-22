/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:16:29 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 11:58:29 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (!a || !b || !*b)
	{
		write(1, "Error\n", 6); 
		return ;
	}
	first = *b;
	*b = (*b)->next;
	if (*a)
		first->next = *a;
	else
		first->next = NULL;
	*a = first;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*first;

	if (!a || !b || !*a)
		return ;
	first = *a;
	*a = (*a)->next;
	if (*b)
		first->next = *b;
	else
		first->next = NULL;
	*b = first;
	write(1, "pb\n", 3);
}

void	ft_sa(t_stack **a)
{
	if (!*a || !a)
		return ;
	if (stack_size(a) <= 1)
		return ;
	ft_sx_move(a); 
	write(1, "sa\n", 3);
}

void	ft_ra(t_stack **a)
{
	if (stack_size(a) <= 1)
		return ;
	ft_rx_move(a);
	write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a)
{
	if (stack_size(a) <= 1)
		return ;
	ft_rrx(a);
	write(1, "rra\n", 4);
}
