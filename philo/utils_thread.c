/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:06:06 by abaccari          #+#    #+#             */
/*   Updated: 2024/01/26 16:49:37 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	init_thread(t_obs *obs)
{
	pthread_t	thread;
	int			i;

	if (pthread_create(&thread, NULL, &watcher, &obs->philo[0]) != 0)
		thread_error("fail to create obs thread", obs);
	i = 0;
	while (i < obs->nb_philo)
	{
		if (pthread_create(&obs->philo[i].thread, NULL, &routine_philo,
				&obs->philo[i]) != 0)
			thread_error("fail to create philo thread", obs);
		i++;
	}
	if (pthread_join(thread, NULL) != 0)
		thread_error("fail to delete obs thread", obs);
	i = 0;
	while (i < obs->nb_philo)
	{
		if (pthread_join(obs->philo[i].thread, NULL) != 0)
			thread_error("fail to delete philo thread", obs);
		i++;
	}
	return ;
}

void	end_thread(t_obs *obs)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&obs->write_lock);
	pthread_mutex_destroy(&obs->meal_lock);
	pthread_mutex_destroy(&obs->dead_lock);
	while (i < obs->nb_philo)
	{
		pthread_mutex_destroy(&obs->fork[i]);
		i++;
	}
	return ;
}

void	thread_error(char *msg, t_obs *obs)
{
	if (msg)
	{
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	}
	if (obs)
		end_thread(obs);
}
