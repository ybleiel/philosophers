/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:59:16 by ybleiel           #+#    #+#             */
/*   Updated: 2022/08/02 17:22:51 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_done_eating(t_philo *philo)
{
	if (philo->data->nr_of_meals == (philo->data->repeat_times * philo->data->philo_count))
	{
		printf("philos finished the spaghetti\n");
		philo->data->life_status = FULL;
		pthread_exit(NULL);
	}
}

int	death_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_time_mutex);
	// usleep(2000);
	// printf("philo: %d current time: %07li, start_eat_time: %07li die_time: %07i\n",philo->id, current_time(philo), philo->start_eat_time, philo->data->die_time);
	// printf("%07li >= %d, philo %d\n", current_time(philo) - philo->start_eat_time, philo->data->die_time, philo->id);
	if (current_time(philo) - philo->start_eat_time >= philo->data->die_time && philo->data->life_status == ALIVE)
	{
		printf("%07li %d is dead\n", current_time(philo), philo->id);
		pthread_mutex_lock(&philo->life_status_mutex);
		philo->data->life_status = DEAD;
		pthread_mutex_unlock(&philo->life_status_mutex);
		return (1);
	}
	else
		pthread_mutex_unlock(&philo->eat_time_mutex);
	return (0);
}
