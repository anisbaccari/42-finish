/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:13:31 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/25 15:38:35 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//strncmp() functions lexicographically compare 
//the null-terminated strings s1 and s2.

#include "libft.h"

int	ft_strncmp(const char *a, const char *b, size_t n)
{
	size_t	i;

	i = 0;
	while (a && b && (n > i) && (a[i] || b[i]))
	{
		if ((unsigned char)a[i] != (unsigned char)b[i])
			return ((unsigned char)a[i] - (unsigned char)b[i]);
		i++;
	}
	return (0);
}
