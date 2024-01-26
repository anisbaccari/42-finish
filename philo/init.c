/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:41:09 by abaccari          #+#    #+#             */
/*   Updated: 2023/12/26 13:18:23 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	ft_init(t_obs *obs, t_philo *philo, pthread_mutex_t *fork, char **argv)
{
	init_struct(obs, philo, fork, argv);
	init_philo(obs, philo);
}

void	init_input(char **argv, t_obs *obs)
{
	obs->nb_philo = ft_atoi(argv[1]);
	obs->time_to_die = ft_atoi(argv[2]);
	obs->time_to_eat = ft_atoi(argv[3]);
	obs->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		obs->max_meals = ft_atoi(argv[5]);
	else
		obs->max_meals = -1;
}

void	init_struct(t_obs *obs, t_philo *philo, pthread_mutex_t *fork,
		char **argv)
{
	int	i;

	pthread_mutex_init(&obs->dead_lock, NULL);
	pthread_mutex_init(&obs->meal_lock, NULL);
	pthread_mutex_init(&obs->write_lock, NULL);
	obs->fork = fork; 
	obs->is_dead = 0;
	obs->philo = philo;
	obs->start = get_time();
	init_input(argv, obs);
	i = 0;
	while (i < obs->nb_philo)
	{
		philo[i].max_meals = obs->max_meals;
		philo[i].is_dead = &obs->is_dead;
		philo[i].meal_lock = &obs->meal_lock;
		philo[i].dead_lock = &obs->dead_lock;
		philo[i].write_lock = &obs->write_lock;
		i++;
	}
}

void	init_philo(t_obs *obs, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < obs->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].nb_meal = 0;
		philo[i].hunger = 0;
		philo[i].start = get_time();
		philo[i].meal_time = get_time();
		philo[i].nb_philo = obs->nb_philo;
		philo[i].time_to_sleep = obs->time_to_sleep;
		philo[i].time_to_eat = obs->time_to_eat;
		philo[i].time_to_die = obs->time_to_die;
		pthread_mutex_init(&obs->fork[i], NULL);
		philo[i].left_fork = &obs->fork[i];
		if (i == 0)
			philo[i].right_fork = &obs->fork[obs->nb_philo - 1];
		else
			philo[i].right_fork = &obs->fork[i - 1];
		i++;
	}
}
