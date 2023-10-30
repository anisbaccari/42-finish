/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:01:26 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 17:48:43 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcpy() function copies n bytes from memory area 
//	src to memory area dst. 
// If dst and src overlap, behavior is unde-
//    fined.  Applications in which dst and src might 
//	overlap should use memmove(3) instead

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!n || dest == src)
		return (dest);
	i = 0;
	while (i < n && dest && src)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
