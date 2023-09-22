/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:12:26 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:37:18 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  The memchr() function locates the first occurrence 
//of c (converted to an unsigned char) in string s.

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n )
{
	size_t	index;

	if (!str)
		return (NULL);
	index = 0;
	while (index < n)
	{
		if (*((unsigned char *)str + index) == ((unsigned char)c))
			return ((void *) str + index);
		index++;
	}
	return (NULL);
}
