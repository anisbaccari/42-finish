/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:30:59 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/24 13:52:14 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the string ’s’ to the given file descriptor
followed by a newline
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
