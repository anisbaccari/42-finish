/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:01 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 11:57:47 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	single_arg(t_bigstack *b, char **argv)
{
	int	i;

	b->splited = 0;
	if (!argv[1][0] || argv[1][0] == ' ')
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	b->argv = ft_split(argv[1], ' ');
	i = 0;
	while (b->argv[i])
	{
		i++;
	}
	b->argc = i - 1;
}

void	multi_arg(t_bigstack *b, char **argv, int argc)
{
	int	i;

	b->argv = (char **)ft_calloc(sizeof(char *), (argc));
	if (!b->argv)
		ft_error(b);
	b->argc = argc - 1;
	b->splited = 1;
	i = 1;
	while (argv[i])
	{
		b->argv[i - 1] = argv[i];
		if (!b->argv[i - 1])
			ft_error(b);
		i++;
	}
}
