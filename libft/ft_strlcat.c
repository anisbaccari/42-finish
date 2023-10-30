/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:05:15 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:39:10 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 
 * appends string src to the end of dst.  It will append at most 
 * //dstsize - strlen(dst) - 1 characters.  It will
 *then NUL-terminate, unless dstsize is 0 or the original
 // dst string was longer than dstsize --
 * // we do if
// ((dstlength + n) == dstsize && dstlength < dstsize)
//	dst[--i] = '\0';
//	to handle the case where the destination buffer is exactly filled to capacity 
//	by the concatenation of the source string, with no room for a null terminator.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	dstlength;

	dstlength = ft_strlen(dst);
	i = dstlength;
	n = 0;
	if (src == NULL)
		return (0);
	if (dst == NULL || dstsize == 0)
		return (ft_strlen(src));
	if (dstlength > dstsize)
		return (ft_strlen(src) + dstsize);
	else
	{
		while ((dstlength + n) < dstsize && src[n])
			dst[i++] = src[n++];
		if ((dstlength + n) == dstsize && dstlength < dstsize)
			dst[--i] = '\0';
		else
			dst[i] = '\0';
		return (dstlength + ft_strlen(src));
	}
}
