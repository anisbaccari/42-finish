/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:27:54 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:37:46 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The memcmp() function compares byte string s1 against byte string s2. 
// Both strings are assumed to be n bytes long

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	if ((!s1 || !s2) || n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (str1[index] == str2[index] && (index < (n - 1)))
		index++;
	return (str1[index] - str2[index]);
}
