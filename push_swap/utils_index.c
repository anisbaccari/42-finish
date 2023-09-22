/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:07 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 13:01:37 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	find_index(t_bigstack *b, t_stack *a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = b->a;
	while (tmp->next)
	{
		if (a->n > tmp->n)
			i++;
		tmp = tmp->next;
	}
	if (a->n > tmp->n)
		i++;
	return (i);
}

void	init_index(t_bigstack *b)
{
	t_stack	*tmp;
	int		index;

	tmp = b->a;
	while (tmp->next)
	{
		index = find_index(b, tmp);
		tmp->index = index;
		tmp = tmp->next;
	}
	index = find_index(b, tmp);
	tmp->index = index;
	return ;
}

int	get_min_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		num;
	int		index;

	i = 0;
	index = 0;
	tmp = *a;
	num = (*a)->n;
	while (*a)
	{
		if ((*a)->n < num)
		{
			num = (*a)->n;
			index = i;
		}
		i++;
		*a = (*a)->next;
	}
	*a = tmp;
	return (index);
}

int	get_max_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		num;
	int		index;

	i = 0;
	index = 0;
	tmp = *a;
	num = (*a)->n;
	while (*a)
	{
		if ((*a)->n > num)
		{
			num = (*a)->n;
			index = i;
		}
		i++;
		*a = (*a)->next;
	}
	*a = tmp;
	return (index);
}
