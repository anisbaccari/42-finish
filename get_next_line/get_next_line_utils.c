/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:11:01 by anis              #+#    #+#             */
/*   Updated: 2023/05/22 18:33:06 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	size;

	if (!src)
		return (0);
	size = ft_strlen(src);
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (size);
}

char	*ft_strdup(char *s, int *index)
{
	int		len;
	int		i;
	char	*mystr;

	len = 0;
	i = -1;
	while (s[len])
	{
		if (s[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	mystr = malloc(sizeof(char) * (len + 1));
	if (!mystr)
		return (NULL);
	while (++i < len)
		mystr[i] = s[i];
	mystr[i] = '\0';
	if (len > 0 && mystr[i - 1] == '\n')
		*index = i - 1;
	return (mystr);
}

void	ft_bzero(void *str, size_t size)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (i < size)
	{
		*(unsigned char *)(str + i) = 0;
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2, int *index)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = -1;
	while (s1[++j])
		str[i++] = s1[j];
	free(s1);
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	if (len > 0 && str [i - 1] == '\n')
		*index = 0;
	return (str);
}
