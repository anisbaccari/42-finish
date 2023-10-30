/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:15:54 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/02 14:02:37 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char **argv)
{
	t_bigstack	big;

	if (argc < 2)
	{
		write(1, "Error", 5);
		write(1, "\n", 1);
		return (0); 
	}
	init_struct(&big, argc, argv); 
	init_arg(&big);
	init_stack(&big);
	init_index(&big);
	init_sort(&big);
	ft_clear_stack(&big.a);
	ft_clear_stack(&big.b); 
	ft_freedom(&big);
	return (0);
}
