/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:03:04 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 15:26:04 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’
*/
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if (len > size)
		len = size;
	if (start >= size)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char ) * (len + 1));
	i = 0;
	if (!str)
		return (NULL);
	if (len > size - start)
		len = size - start;
	while ((len > i) && s[start + i] && (start < size))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
