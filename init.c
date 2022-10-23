/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:41:16 by ybleiel           #+#    #+#             */
/*   Updated: 2022/06/13 13:46:57 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		data->repeat_times = ft_atoi(argv[5]);
	data->start_time = get_time();
	data->nr_of_meals = 0;
	data->forks_on_table = ft_atoi(argv[1]);
	data->life_status = ALIVE;
}

void	ft_init_philos(t_philo *philo, t_data *data, int nr_philos)
{
	int i;

	i = 0;
	while (i < nr_philos)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].forks_in_hand = 0;
		philo[i].start_eat_time = 0;
		philo[i].r_fork = ON_THE_TABLE;
		philo[i].l_fork = ON_THE_TABLE;
		pthread_mutex_init(&philo[i].nr_meals_mutex, NULL);
		pthread_mutex_init(&philo[i].nr_forks_mutex, NULL);
		pthread_mutex_init(&philo[i].l_fork_mutex, NULL);
		pthread_mutex_init(&philo[i].r_fork_mutex, NULL);
		pthread_mutex_init(&philo[i].eat_time_mutex, NULL);
		pthread_mutex_init(&philo[i].life_status_mutex, NULL);
		i++;
	}
}
