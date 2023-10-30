/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:55:27 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:40:20 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memmove() function copies len bytes from string src to string dst.
//  The two strings may overlap; the copy is always
//     done in a non-destructive manner.

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (NULL);
	if (dest > src)
	{
		i = 0;
		while (n--)
		{
			(*(unsigned char *)(dest + n)) = (*(unsigned char *)(src + n));
		}
	}
	else
	{
		i = 0;
		while (n--)
		{
			(*(unsigned char *)(dest + i)) = (*(unsigned char *)(src + i));
			i++;
		}
	}
	return (dest);
}
