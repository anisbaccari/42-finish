/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:42:27 by abaccari          #+#    #+#             */
/*   Updated: 2024/01/08 16:14:38 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

void	thread_msg(char *s, t_philo *p)
{
	size_t	clock;

	if (p)
	{
		pthread_mutex_lock(p->write_lock);
		clock = get_time() - p->start;
		if (is_alive(p))
			printf("[%zu] (%i) %s\n", clock, p->id, s);
		pthread_mutex_unlock(p->write_lock);
	}
}

void	thread_debug(t_philo *p)
{
	pthread_mutex_lock(p->write_lock);
	printf("[%zu] philo(%i) fork  L : %p R: %p\n eated : %i\n", get_time(),
		p->id, p->left_fork, p->right_fork, p->nb_meal);
	pthread_mutex_unlock(p->write_lock);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "get time of day() error\n", 25);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t time_tosleep)
{
	size_t	begin;

	begin = get_time();
	while ((get_time() - begin) < time_tosleep)
		usleep(500);
	return ;
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
