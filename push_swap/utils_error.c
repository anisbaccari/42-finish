/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:24 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/03 14:23:14 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_error(t_bigstack *b)
{
	int	i;

	i = 0;
	write(1, "Error", 5);
	write(1, "\n", 1);
	if (b->argv)
	{
		if (b->splited == 0)
		{
			while (b->argv[i])
			{
				free(b->argv[i]);
				i++;
			}
		}
		free(b->argv);
	}
	if (b->a)
		ft_clear_stack(&b->a);
	if (b->b)
		ft_clear_stack(&b->b);
	exit(EXIT_FAILURE);
}

void	ft_freedom(t_bigstack *b)
{
	int	i;

	i = 0;
	if (b->splited == 0)
	{
		while (b->argv[i])
		{
			free(b->argv[i]);
			i++;
		}
	}
	free(b->argv);
}
