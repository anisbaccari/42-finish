/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:20:08 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 13:00:50 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	init_arg(t_bigstack *b)
{
	arg_char(b);
	arg_type(b);
	arg_limit(b);
	arg_double(b);
}

void	init_stack(t_bigstack *big)
{
	t_stack	*a;
	int		i;

	i = 0;
	while (big->argv[i])
	{
		a = ft_calloc(sizeof(t_stack), 1);
		if (!a)
		{
			free(a);
			return ;
		}
		a->next = NULL;
		addlast_list(big, a, big->argv[i]);
		i++;
	}
}

void	init_struct(t_bigstack *b, int argc, char **argv)
{
	b->a = NULL;
	b->b = NULL;
	b->argv = NULL;
	b->splited = 0;
	if (argc == 2)
		single_arg(b, argv);
	else
		multi_arg(b, argv, argc);
}
