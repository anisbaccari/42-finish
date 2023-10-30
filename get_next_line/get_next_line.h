/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:34:27 by anis              #+#    #+#             */
/*   Updated: 2023/05/29 12:38:09 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef  BUFFER_SIZE
#  define  BUFFER_SIZE 42
# endif
# if BUFFER_SIZE > 10000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# elif BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	ft_bzero(void *str, size_t size);
char	*ft_strdup(char *s, int *index);
char	*ft_strjoin(char *s1, char *s2, int *index);
#endif