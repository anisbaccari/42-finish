/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:17:24 by abaccari          #+#    #+#             */
/*   Updated: 2023/09/20 14:10:48 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_atoi(const char *str)
{
	int		signe;
	long	reste;
	int		i;

	if (!str)
		return (0);
	i = 0;
	signe = 1;
	reste = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		if (str[i++] == '-')
			signe *= -1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		reste = (reste * 10) + (str[i++] - 48);
		if (reste < 0 && signe < 0)
			return (0);
		if (reste < 0 && signe > 0)
			return (-1);
	}
	return (reste * signe);
}

int	ft_is_number(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

char	*ft_getsign(char *str, int *is_neg)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*is_neg *= -1;
		str++;
	}
	return (str);
}

long int	ft_long_atoi(char *str, t_bigstack *b)
{
	int			is_neg;
	long int	nbr;
	long int	tmp;

	is_neg = 1;
	if (!str)
		return (0);
	is_neg = 1;
	nbr = 0;
	tmp = 0;
	while (ft_isspace(*str))
		str++;
	str = ft_getsign(str, &is_neg);
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		if (nbr < tmp)
			ft_error(b);
		tmp = nbr;
		str++;
	}
	return ((nbr * is_neg));
}
