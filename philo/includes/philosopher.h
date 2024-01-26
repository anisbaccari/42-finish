/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaccari <abaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:35:24 by abaccari          #+#    #+#             */
/*   Updated: 2023/12/26 13:21:25 by abaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef PHILOMAX
#  define PHILOMAX 250
# endif

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				nb_meal;
	int				*is_dead;
	int				max_meals;
	int				nb_philo;
	int				hunger;
	size_t			start;
	size_t			meal_time;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			time_to_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	struct timeval	time;

}					t_philo;

typedef struct s_observer
{
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork;
	t_philo			*philo;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			start;
	int				is_dead;
	int				nb_philo;
	int				max_meals;
}					t_obs;

//*************INIT************//
void				ft_init(t_obs *obs, t_philo *philo, pthread_mutex_t *fork,
						char **argv);
void				init_input(char **argv, t_obs *obs);
void				init_philo(t_obs *osb, t_philo *p);
void				init_struct(t_obs *obs, t_philo *philo,
						pthread_mutex_t *fork, char **argv);
void				init_thread(t_obs *obs);
//*************ROUTINE************//
void				*routine_philo(void *p);
void				*watcher(void *arg);
int					philo_max_meal(t_philo *p);
int					is_alive(t_philo *p);
void				is_eating(t_philo *p);
void				is_thinking(t_philo *p);
int					death_of_philo(t_philo *p, size_t time_to_die);
void				is_sleeping(t_philo *p);
int					ft_dead(t_philo *thewatcher);
int					is_hungry(int total, t_philo *p);
//*************THREAD************//
void				thread_msg(char *s, t_philo *p);
void				end_thread(t_obs *obs);
void				thread_debug(t_philo *p);
void				thread_error(char *msg, t_obs *obs);
//*************UTILS************//
int					is_digit(char *s);
size_t				get_time(void);
void				ft_usleep(size_t time_tosleep);
int					ft_atoi(const char *str);
int					args_checker(char **arg);
int					ft_strlen(char *str);
#endif