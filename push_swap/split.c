/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anis <anis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:16:49 by abaccari          #+#    #+#             */
/*   Updated: 2023/10/18 18:05:42 by anis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	count_word(char const *s, char sep)
{
	int	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		while (*s && (*s == sep))
			s++;
		if (*s)
			count++;
		while (*s && (*s != sep))
			s++;
	}
	return (count);
}

char	*get_word(char const *s, char c)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	size = 0;
	while (s[size] && s[size] != c)
		size++;
	word = (char *)ft_calloc(sizeof(char *), (size + 1));
	if (!word)
	{
		return (NULL);
	}
	while (s[i] && i < size)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**insert_to(char **tab, char const *s, char c)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			tab[i] = get_word(s, c);
			if (!tab[i])
			{
				while (*tab)
					free(tab++);
				free(tab);
				return (NULL);
			}
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;

	size = 0;
	size = count_word(s, c);
	tab = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (!tab)
		return (NULL);
	tab = insert_to(tab, s, c);
	tab[size] = NULL;
	return (tab);
}
