/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:58:20 by ybleiel           #+#    #+#             */
/*   Updated: 2022/06/13 13:55:02 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -m;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	return (j * m);
}

int	check_life_status(t_philo *philo)
{
	int	status;

	status = 1;
	pthread_mutex_lock(&philo->life_status_mutex);
	if (philo->data->life_status == DEAD)
		status = 0;
	pthread_mutex_unlock(&philo->life_status_mutex);
	return (status);
}