/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:59 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/03 12:22:31 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	
*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return ((char *)ptr);
		ptr++;
	}
	if (ptr && *ptr == (char) c)
		return ((char *)ptr);
	return (NULL);
}
