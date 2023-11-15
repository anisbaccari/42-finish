/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:45:37 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/07 13:06:40 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	lengthstring(long nb)
{
	unsigned int	i;

	i = 0 ;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_unitoa(unsigned int n)
{
	int		lenght;
	long	nb;
	char	*str;

	nb = n;
	lenght = lengthstring(n);
	str = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (NULL);
	*(str + lenght) = '\0';
	lenght--;
	if (nb == 0)
		*(str + lenght) = '0';
	else if (nb < 0)
	{
		nb *= -1;
		*(str +0) = '-';
	}
	while (nb > 0 && str)
	{
		*(str + lenght) = (48 + (nb % 10));
		lenght--;
		nb /= 10;
	}
	return (str);
}

int	ft_int(int n)
{
	int		i;
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	i = ft_strlen(str);
	write(1, str, i);
	free (str);
	return (i);
}

int	ft_unsignedint(unsigned int n)
{
	int		size;
	char	*str;

	size = 0;
	str = ft_unitoa(n);
	if (!str)
		return (-1);
	size = ft_string(str);
	free(str);
	return (size);
}
