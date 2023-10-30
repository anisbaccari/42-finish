/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:54:57 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/10 15:24:46 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa(unsigned int x, char flag)
{
	int			i;
	char		str[20];
	char		*base_character;
	int			size;

	if (flag == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	i = 0;
	if (x == 0)
		return (write(1, "0", 1));
	if (!x)
		return (-1);
	while (x != 0)
	{
		str[i] = base_character[x % 16];
		x = x / 16;
		i++;
	}
	size = i;
	while (i--)
		write(1, &str[i], 1);
	return (size);
}
