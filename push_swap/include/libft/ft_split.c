/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:17:59 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/22 15:25:47 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/***
 * Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer
 * >  nbword 
 * > lenghtword
 * > getword 
 * > freeword 
 * static funcion ! 
*/

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (*(s + 1) == c || !*(s + 1))
				i++;
			s++;
		}
	}
	return (i);
}

static char	*ft_getword(char const *s, unsigned int *start, char c)
{
	size_t	len;

	while (s[*start] && s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start] && s[*start] != c)
	{
		(*start)++;
		len++;
	}
	return (ft_substr(s, *start - len, len));
}

static void	ft_free(char **s, size_t wordlen)
{
	size_t	i;

	i = 0;
	while (i < wordlen)
		free(s[i++]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char			**words;
	size_t			lenght;
	size_t			i;
	unsigned int	start;

	if (!s)
		return (0);
	lenght = ft_count_words(s, c);
	words = ft_calloc(lenght + 1, sizeof(char *));
	if (!words)
		return (NULL);
	i = -1;
	start = 0;
	while (++i < lenght)
	{
		words[i] = ft_getword(s, &start, c);
		if (!words[i])
		{
			ft_free(words, i);
			return (NULL);
		}
	}
	words[i] = NULL;
	return (words);
}
