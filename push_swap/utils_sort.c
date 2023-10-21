/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:20 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/23 16:03:48 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_order(t_bigstack *b)
{
	t_stack	*first;
	t_stack	**a;
	int		tmp;

	a = &b->a;
	first = *a;
	tmp = (*a)->n;
	while (*a)
	{
		if (tmp > (*a)->n)
		{
			*a = first;
			return (0);
		}
		tmp = (*a)->n;
		*a = (*a)->next;
	}
	*a = first;
	return (1);
}

void	tri_sort(t_bigstack *b)
{
	int	min;
	int	max;

	min = get_min_index(&b->a);
	max = get_max_index(&b->a);
	if (min == 0 && max == 1)
	{
		ft_sa(&b->a);
		ft_ra(&b->a);
	}
	else if (min == 1 && max == 2)
		ft_sa(&b->a);
	else if (min == 2 && max == 0)
	{
		ft_sa(&b->a);
		ft_rra(&b->a);
	}
	else if (min == 1 && max == 0)
		ft_ra(&b->a);
	else
		ft_rra(&b->a);
	return ;
}

void	ft_five_sort(t_bigstack *b)
{
	while (stack_size(&b->a) > 3)
	{
		if (get_min_index(&b->a) == 0)
			ft_pb(&b->a, &b->b);
		else if (get_min_index(&b->a) == stack_size(&b->a))
			ft_rra(&b->a);
		else
			ft_ra(&b->a);
	}
	if (!(get_min_index(&b->a) == 0 && get_max_index(&b->a) == 2))
		tri_sort(b);
	while (stack_size(&b->b))
	{
		ft_pa(&b->a, &b->b);
	}
	return ;
}

void	init_sort(t_bigstack *b)
{
	while (!is_order(b))
	{
		if (stack_size(&b->a) == 2)
		{
			ft_ra(&b->a);
			return ;
		}
		else if (stack_size(&b->a) == 3)
			tri_sort(b);
		else if (stack_size(&b->a) <= 5)
			ft_five_sort(b);
		else
			ft_radix(b, 0);
	}
	return ;
}
