/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:48:12 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/10 15:25:02 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_string(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
