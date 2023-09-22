/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:52:37 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:38:10 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strchr() function locates the first occurrence of 
//c (converted to a char) in the string pointed to by s.  The termi-
//     nating null character is considered to be part of the string; 
// therefore if c is `\0', the functions locate the terminating
//     `\0'.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*buffer;
	int			length;

	if (!s)
		return (0);
	length = ft_strlen(s);
	buffer = ((char *)s + length);
	while (length >= 0 && s)
	{
		if (*buffer == (char) c)
			return ((char *)buffer);
		buffer--;
		length--;
	}
	if (c == '\0')
		return ((char *)buffer);
	return (0);
}
