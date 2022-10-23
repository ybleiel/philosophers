/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybleiel <ybleiel@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:28:49 by ybleiel           #+#    #+#             */
/*   Updated: 2022/06/27 15:22:05 by ybleiel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *) ptr;
	while (1 && philo->data->life_status == ALIVE)
	{
		if (death_check(philo) == 1)
			return (NULL) ;
		ft_take_l_fork(philo);
		ft_take_r_fork(philo);
		if (philo->data->life_status == ALIVE)
			ft_eating(philo);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	int i;
	t_philo *philo;
	t_data data;

	i = 0;
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (argc < 2 || argc > 6)
		return (0);
	ft_init_data(&data, argv);
	ft_init_philos(philo, &data, ft_atoi(argv[1]));
	pthread_mutex_init(&philo->l_fork_mutex, NULL);
	while (i < ft_atoi(argv[1]))
	{
		pthread_create(&philo[i].thread, NULL, &routine, (void *) &philo[i]);
		i++;
	}
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&philo->l_fork_mutex);
	pthread_exit(NULL);
	return (0);
}
