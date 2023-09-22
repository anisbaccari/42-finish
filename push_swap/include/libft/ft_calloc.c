/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:03:41 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:43:12 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * pas de sizeof car deja donner
*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*buffer;

	total = count * size;
	buffer = (void *)malloc(total);
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, total);
	return (buffer);
}
