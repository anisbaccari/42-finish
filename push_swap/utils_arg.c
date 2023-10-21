/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:01 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/02 15:59:49 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	arg_char(t_bigstack *b)
{
	int	i;

	i = 0;
	while (b->argv[i])
	{
		if (*b->argv[i] == 43 || *b->argv[i] == 45)
		{
			if (!(b->argv[i][1] >= 48 && b->argv[i][1] <= 59))
				ft_error(b);
		}
		else if (*b->argv[i] == 34)
		{
			if (!(b->argv[i][1] >= 48 && b->argv[i][1] <= 59)
				&& !(*b->argv[i] == 43 || *b->argv[i] == 45))
				ft_error(b);
		}
		else if (*b->argv[i] == '\0')
			ft_error(b);
		i++;
	}
}

void	arg_type(t_bigstack *b)
{
	int	i;

	i = 0;
	while (b->argv[i])
	{
		if (!ft_is_number(b->argv[i]))
			ft_error(b);
		i++;
	}
}

void	arg_double(t_bigstack *b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (b->argv[i])
	{
		while (b->argv[j])
		{
			if (ft_atoi(b->argv[i]) == ft_atoi(b->argv[j]))
				ft_error(b);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	arg_limit(t_bigstack *b)
{
	int	i;

	i = 0;
	while (b->argv[i])
	{
		if (ft_long_atoi(b->argv[i], b) > INT32_MAX || ft_long_atoi(b->argv[i],
				b) < INT32_MIN)
			ft_error(b);
		i++;
	}
}
