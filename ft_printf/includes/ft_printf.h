/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:44:34 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/10 15:18:03 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

int	ft_hexa(unsigned int n, char flag);
int	ft_string(char *args);
int	ft_int( int n);
int	ft_char(int args);
int	ft_unsignedint(unsigned int n);
int	ft_pointer(size_t n);
int	ft_printf(const char *str, ...);
#endif