/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:36:30 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:38:21 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strstr() function locates the first occurrence of 
//the null-terminated string needle in the null-terminated string haystack

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!haystack || !needle)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (i < len && *(haystack + i) != '\0')
	{
		while (*(haystack + i + j) == *(needle + j) && *(needle + j) != '\0'
			&& *(haystack + i + j) != '\0' && (i + j) < len)
			j++;
		if (*(needle + j) == '\0')
			return ((char *)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
