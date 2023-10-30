/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:00:59 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/24 13:56:57 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
		if we use  s[i] instead of *s  > the return  is : return ((char *)&s[i]);
		because we cant cast a const char * to a char *;
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
