/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:23:59 by abaccari          #+#    #+#             */
/*   Updated: 2023/04/24 13:51:23 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the character ’c’ to the given file
descriptor
*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
