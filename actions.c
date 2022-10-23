/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:44:57 by ybleiel           #+#    #+#             */
/*   Updated: 2022/08/02 17:28:52 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_philo *philo)
{
	printf("philo: %d current time: %07li, start_eat_time: %07li die_time: %07i\n",philo->id, current_time(philo), philo->start_eat_time, philo->data->die_time);
	philo_done_eating(philo);
	// pthread_mutex_lock(&philo->nr_forks_mutex);
	// printf("philo %d forks in hand: %d\n", philo->id, philo->forks_in_hand);
	if (philo->forks_in_hand == 2)
	{
		pthread_mutex_lock(&philo->nr_meals_mutex);
		philo->data->nr_of_meals++;
		pthread_mutex_unlock(&philo->nr_meals_mutex);
		pthread_mutex_lock(&philo->eat_time_mutex);
		philo->start_eat_time = current_time(philo);
		printf("%07li %d is eating\n", current_time(philo), philo->id);
		pthread_mutex_unlock(&philo->eat_time_mutex);
		ft_usleep(philo->data->eat_time, philo);
		ft_put_down_l_fork(philo);
		ft_put_down_r_fork(philo);
		ft_sleeping(philo);
		// printf("philo %d forks in hand: %d\n", philo->id, philo->forks_in_hand);
	}
	// pthread_mutex_unlock(&philo->nr_forks_mutex);
}

void	ft_sleeping(t_philo *philo)
{
	if (philo->data->life_status == ALIVE)
	{
		printf("%07li %d is sleeping\n", current_time(philo), philo->id);
		ft_usleep(philo->data->sleep_time, philo);
		ft_thinking(philo);
	}
}

void	ft_thinking(t_philo *philo)
{
	// if (philo->data->life_status == ALIVE)
	// {
	// 	if (philo->data->eat_time + philo->data->sleep_time < philo->data->die_time)
	// 		usleep(10000);
	// 	printf("%07li %d is thinking\n", current_time(philo), philo->id);
	// }
	// printf("philo: %d current time: %07li, start_eat_time: %07li die_time: %07i\n",philo->id, current_time(philo), philo->start_eat_time, philo->data->die_time);
	printf("%07li %d is thinking\n", current_time(philo), philo->id);
}