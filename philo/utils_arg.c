/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:42:15 by abaccari          #+#    #+#             */
/*   Updated: 2023/12/20 13:46:16 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

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

int	is_digit(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	args_checker(char **arg)
{
	if (ft_atoi(arg[1]) <= 0 || ft_atoi(arg[1]) > PHILOMAX
		|| is_digit(arg[1]) == 1)
		return (1);
	if (ft_atoi(arg[2]) <= 0 || is_digit(arg[2]) == 1)
		return (1);
	if (ft_atoi(arg[3]) <= 0 || is_digit(arg[3]) == 1)
		return (1);
	if (ft_atoi(arg[4]) <= 0 || is_digit(arg[4]) == 1)
		return (1);
	if (arg[5] && (ft_atoi(arg[5]) <= 0 || is_digit(arg[5]) == 1))
		return (1);
	return (0);
}
