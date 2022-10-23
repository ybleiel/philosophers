/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:58:13 by ybleiel           #+#    #+#             */
/*   Updated: 2022/08/02 17:15:48 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_l_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
		usleep(5000);
	pthread_mutex_lock(&philo->l_fork_mutex);
	// printf("forks on table: %d\n", philo->data->forks_on_table);
	if (philo->l_fork == ON_THE_TABLE && philo->data->forks_on_table >= 1)
	{
		philo->l_fork = TAKEN;
		pthread_mutex_unlock(&philo->l_fork_mutex);
		pthread_mutex_lock(&philo->nr_forks_mutex);
		philo->forks_in_hand++;
		philo->data->forks_on_table--;
		pthread_mutex_unlock(&philo->nr_forks_mutex);
		printf("%07li %d has taken left fork\n", current_time(philo), philo->id);
		// printf("forks on table: %d\n", philo->data->forks_on_table);
	}
	else
		pthread_mutex_unlock(&philo->l_fork_mutex);
	// printf("forks on table: %d\n", philo->data->forks_on_table);
}

void	ft_take_r_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork_mutex);
	if (philo->r_fork == ON_THE_TABLE && philo->data->forks_on_table >= 0)
	{
		philo->r_fork = TAKEN;
		pthread_mutex_unlock(&philo->r_fork_mutex);
		pthread_mutex_lock(&philo->nr_forks_mutex);
		philo->forks_in_hand++;
		philo->data->forks_on_table--;
		pthread_mutex_unlock(&philo->nr_forks_mutex);
		printf("%07li %d has taken right fork\n", current_time(philo), philo->id);
		// printf("forks on table: %d\n", philo->data->forks_on_table);
	}
	else
		pthread_mutex_unlock(&philo->r_fork_mutex);
}

void	ft_put_down_l_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork_mutex);
	if (philo->l_fork == TAKEN)
	{
		philo->l_fork = ON_THE_TABLE;
		pthread_mutex_unlock(&philo->l_fork_mutex);
		pthread_mutex_lock(&philo->nr_forks_mutex);
		philo->forks_in_hand--;
		philo->data->forks_on_table++;
		pthread_mutex_unlock(&philo->nr_forks_mutex);
		// printf("%07li %d put down left fork\n", current_time(philo), philo->id);
		// printf("forks on table: %d\n", philo->data->forks_on_table);
		pthread_mutex_unlock(&philo->l_fork_mutex);
	}
}

void	ft_put_down_r_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork_mutex);
	if (philo->r_fork == TAKEN)
	{
		philo->r_fork = ON_THE_TABLE;
		pthread_mutex_unlock(&philo->l_fork_mutex);
		pthread_mutex_lock(&philo->nr_forks_mutex);
		philo->forks_in_hand--;
		philo->data->forks_on_table++;
		pthread_mutex_unlock(&philo->nr_forks_mutex);
		// printf("%07li %d put down right fork\n", current_time(philo), philo->id);
		// printf("forks on table: %d\n", philo->data->forks_on_table);
		pthread_mutex_unlock(&philo->r_fork_mutex);
	}
	else
		pthread_mutex_unlock(&philo->l_fork_mutex);
}
