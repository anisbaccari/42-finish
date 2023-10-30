/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:52:37 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:39:33 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The strdup() function allocates sufficient memory for a copy of the string s1,
// does the copy, and returns a pointer to it.
//  The pointer may subsequently be used as an argument 
//	to the function free(3)

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	size;
	char	*mystr;

	size = ft_strlen(str) +1 ;
	mystr = (malloc (sizeof (char) * size));
	if (!mystr)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		mystr[i] = str[i];
		i++;
	}
	mystr[i] = '\0';
	return (mystr);
}
