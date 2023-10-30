/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:45:19 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/09 18:07:51 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_pointer(size_t x)
{
	char	str[30];
	char	*base_character;
	int		i;
	int		size;

	base_character = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	size = 2;
	if (x == 0)
	{
		write(1, "0", 1);
		return (size + 1);
	}
	while (x != 0)
	{
		str[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	size += i;
	while (i--)
		write(1, &str[i], 1);
	return (size);
}
