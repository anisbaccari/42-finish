/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:41:55 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 17:48:21 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***
 * Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled
 *  - lenghtstring -> donne la lomgueur du chiffres a ecrire 
 * - 
*/

#include "libft.h"

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

char	*ft_itoa(int n)
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
