/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:57:25 by anis              #+#    #+#             */
/*   Updated: 2023/05/29 12:24:16 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_endln(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n' || str[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

static char	*ft_read(int fd, int *index_nl, char *str, char *line)
{
	int		count;
	int		size;
	char	buffer[BUFFER_SIZE + 1];

	while (*index_nl == -1)
	{
		ft_bzero(buffer, BUFFER_SIZE +1);
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(line);
			ft_bzero(str, BUFFER_SIZE +1);
			return (NULL);
		}
		if (count == 0)
		{
			ft_bzero(str, BUFFER_SIZE +1);
			break ;
		}
		size = ft_endln(buffer);
		ft_strlcpy(str, &buffer[size], BUFFER_SIZE + 1);
		ft_strlcpy(buffer, buffer, size + 1);
		line = ft_strjoin(line, buffer, index_nl);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*line;
	int			index_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index_nl = -1;
	line = ft_strdup(str, &index_nl);
	if (!line)
		return (NULL);
	ft_strlcpy(str, &str[index_nl + 1], BUFFER_SIZE +1);
	line = ft_read(fd, &index_nl, str, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
