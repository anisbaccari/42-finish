/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:54:36 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/23 17:15:39 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
  * The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area.
 *
 */
#include "libft.h"

void	ft_bzero( void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*((unsigned char *)s + i) = '\0';
		i++;
	}
}
