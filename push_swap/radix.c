/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:16:41 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 12:59:47 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_radix(t_bigstack *b, int byte)
{
	int		i;
	t_stack	**a;

	a = &b->a;
	while (is_order(b) == 0)
	{
		i = stack_size(a);
		while (i)
		{
			if ((((*a)->index >> byte) & 1) == 0)
				ft_pb(&b->a, &b->b);
			else
				ft_ra(&b->a);
			i--;
		}
		byte++;
		while (stack_size(&b->b))
			ft_pa(&b->a, &b->b);
	}
}
