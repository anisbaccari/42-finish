/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:42:01 by abaccari          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:17 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	*routine_philo(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (is_alive(philo))
	{
		is_eating(philo);
		is_sleeping(philo);
		is_thinking(philo);
	}
	return (p);
}

int	is_alive(t_philo *p)
{
	pthread_mutex_lock(p->dead_lock);
	if (*p->is_dead == 1)
	{
		pthread_mutex_unlock(p->dead_lock);
		return (0);
	}
	pthread_mutex_unlock(p->dead_lock);
	return (1);
}

void	is_eating(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	thread_msg(" has taken right fork", p);
	if (p->nb_philo == 1)
	{
		ft_usleep(p->time_to_die);
		pthread_mutex_unlock(p->right_fork);
		return ;
	}
	pthread_mutex_lock(p->left_fork);
	thread_msg(" has taken left fork", p);
	p->eating = 1;
	thread_msg("is eating", p);
	pthread_mutex_lock(p->meal_lock);
	p->nb_meal += 1;
	p->meal_time = get_time();
	pthread_mutex_unlock(p->meal_lock);
	ft_usleep(p->time_to_eat);
	p->eating = 0;
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	is_thinking(t_philo *p)
{
	thread_msg("is thinking ..", p);
}

void	is_sleeping(t_philo *p)
{
	thread_msg("is sleeping", p);
	ft_usleep(p->time_to_sleep);
}
