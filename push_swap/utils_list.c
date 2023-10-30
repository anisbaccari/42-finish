/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:10 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 13:02:43 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	stack_size(t_stack **a)
{
	size_t	i;
	t_stack	*first;

	i = 1;
	first = *a;
	if (!a || !*a)
		return (0);
	while ((*a)->next)
	{
		*a = (*a)->next;
		++i;
	}
	*a = first;
	return (i);
}

void	ft_clear_stack(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!a || !*a)
		return ;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
		i++;
	}
}

t_stack	*getlast(t_stack *a)
{
	while ((a)->next)
		a = (a)->next;
	return (a);
}

t_stack	*addlast_list(t_bigstack *big, t_stack *new, char *s)
{
	t_stack	*tmp;
	int		num;

	if (big->a == NULL)
	{
		big->a = new;
		num = ft_atoi(s);
		new->n = num;
		return (new);
	}
	tmp = getlast(big->a);
	tmp->next = new;
	num = ft_atoi(s);
	new->n = num;
	return (new);
}
