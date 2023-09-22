/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:55:27 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 15:25:24 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The memset() function writes len bytes of value 
//c (converted to an unsigned char) to the string b.

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s)
	{
		*((unsigned char *)s + i) = c;
		i++;
	}
	return (s);
}
