/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:47 by ybleiel           #+#    #+#             */
/*   Updated: 2022/06/17 13:47:24 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

# define DEAD 1
# define FULL 2
# define ALIVE 0
# define TAKEN 200
# define ON_THE_TABLE 100

typedef struct	s_data
{
	int	philo_count;
	int die_time;
	int eat_time;
	int sleep_time;
	int repeat_times;
	int nr_of_meals;
	int forks_on_table;
	int life_status;
	long start_time;
}				t_data;

typedef struct	s_philo
{
	int	id;
	int l_fork;
	int r_fork;
	int forks_in_hand;
	long start_eat_time;
	int time_without_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork_mutex;
	pthread_mutex_t	r_fork_mutex;
	pthread_mutex_t	nr_meals_mutex;
	pthread_mutex_t	nr_forks_mutex;
	pthread_mutex_t	eat_time_mutex;
	pthread_mutex_t	life_status_mutex;
	t_data *data;
}				t_philo;

void		ft_init_data(t_data *data, char **argv);
int			ft_atoi(const char *str);
long		current_time(t_philo *philo);
void		ft_init_philos(t_philo *philo, t_data *data, int nr_philos);
void		ft_take_l_fork(t_philo *philo);
void		ft_take_r_fork(t_philo *philo);
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_thinking(t_philo *philo);
void		ft_usleep(int duration, t_philo *philo);
int			death_check(t_philo *philo);
void		philo_done_eating(t_philo *philo);
void		ft_put_down_l_fork(t_philo *philo);
void		ft_put_down_r_fork(t_philo *philo);
long		get_time(void);
int			check_life_status(t_philo *philo);

# endif