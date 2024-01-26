/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_obs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:41:27 by abaccari          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:56 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int	is_hungry(int total, t_philo *p)
{
	if (total == p[0].nb_philo)
	{
		pthread_mutex_lock(p[0].dead_lock);
		*(p->is_dead) = 1;
		pthread_mutex_unlock(p[0].dead_lock);
		return (0);
	}
	return (1);
}

int	philo_max_meal(t_philo *p)
{
	int	i;
	int	total_meals;

	if (p->max_meals > 0)
	{
		total_meals = 0;
		i = 0;
		while (i < p->nb_philo)
		{
			pthread_mutex_lock(p->meal_lock);
			if (p[i].nb_meal >= p[i].max_meals)
				total_meals++;
			pthread_mutex_unlock(p->meal_lock);
			i++;
		}
		if (!is_hungry(total_meals, p))
			return (1);
	}
	return (0);
}

int	death_of_philo(t_philo *p, size_t time_to_die)
{
	pthread_mutex_lock(p->meal_lock);
	if ((get_time() - p->meal_time) >= time_to_die && p->eating == 0)
	{
		pthread_mutex_unlock(p->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(p->meal_lock);
	return (0);
}

int	ft_dead(t_philo *thewatcher)
{
	int	i;

	i = 0;
	while (i < thewatcher[0].nb_philo)
	{
		if (death_of_philo(&thewatcher[i], thewatcher[i].time_to_die))
		{
			thread_msg("is dead", &thewatcher[i]);
			pthread_mutex_lock(thewatcher[0].dead_lock);
			*thewatcher->is_dead = 1;
			pthread_mutex_unlock(thewatcher[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*watcher(void *arg)
{
	t_philo	*thewatcher;

	thewatcher = (t_philo *)arg;
	while (1)
		if (philo_max_meal(thewatcher) || ft_dead(thewatcher))
			break ;
	return (arg);
}
