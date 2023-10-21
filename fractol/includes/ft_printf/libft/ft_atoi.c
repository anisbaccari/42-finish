/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:27:54 by abaccari          #+#    #+#             */
/*   Updated: 2023/05/10 15:25:31 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
