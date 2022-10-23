/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:36:19 by ybleiel           #+#    #+#             */
/*   Updated: 2022/07/29 16:50:46 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tp;
	long			start_time;

	gettimeofday(&tp, NULL);
	start_time = tp.tv_sec * 1000;
	start_time += tp.tv_usec / 1000;
	return (start_time);
}

long	current_time(t_philo *philo)
{
	long	current_time;

	current_time = get_time() - philo->data->start_time;
	return (current_time);
}

void	ft_usleep(int duration, t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	while (get_time() - start_time < duration)
	{
		usleep(50);
		if (death_check(philo) == 1)
			break ;
	}
}
