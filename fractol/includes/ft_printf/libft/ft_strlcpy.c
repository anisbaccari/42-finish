/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:15 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:38:47 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *  size_t n prend en compte le Null terminate
 *  copies up to dstsize - 1 characters from the string src to dst, 
 * //NUL-terminating the result if dstsize is not 0
*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	lenght;

	if (!dst || !src)
		return (0);
	lenght = ft_strlen(src);
	i = 0 ;
	if (n == 0)
		return (lenght);
	while (((n - 1) > i) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lenght);
}
