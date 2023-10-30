/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:48:42 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/10 15:15:39 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	- ft_convert ;
*	- ft_flags;
*	- ft_printf; 
*
*/

#include "../includes/ft_printf.h"

static int	ft_conversion(va_list *args, char flag)
{
	int	size;

	size = 0;
	if (flag == 's')
		size = ft_string(va_arg(*args, char *));
	else if (flag == 'c')
		size = ft_char(va_arg(*args, int ));
	else if (flag == 'u')
		size = ft_unsignedint(va_arg(*args, unsigned int));
	else if (flag == 'x')
		size = ft_hexa(va_arg(*args, unsigned int), 'x');
	else if (flag == 'X')
		size = ft_hexa(va_arg(*args, unsigned int), 'X');
	else if (flag == 'i' || flag == 'd')
		size = ft_int(va_arg(*args, int));
	else if (flag == 'p')
		size = ft_pointer(va_arg(*args, size_t));
	else if (flag == '%')
		size = ft_char('%');
	else
		return (-1);
	return (size);
}

static int	findchr(const char *s, char str)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (s[i++] == str)
			return (i - 1);
	return (-1);
}

static int	ft_flag(va_list *args, char **str)
{
	char	flag;
	int		size;

	(*str)++;
	size = 0;
	if (!ft_strchr("cspdiuxX%", **str))
		return (-1);
	flag = "cspdiuxX%"[findchr("cspdiuxX%", **str)];
	size += ft_conversion(args, flag);
	(*str)++;
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '\0' && str[i] != '%')
			i++;
		write(1, str, i);
		str += i;
		len += i;
		if (*str && *str == '%')
			len += ft_flag(&args, (char **)&str);
	}
	va_end(args);
	return (len);
}
