/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:14:05 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/21 14:14:07 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* initialzes all fork mutexes */
void	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

/* initialzes the mutex for the printing function */
void	init_logs_mutex(t_data *data)
{
	pthread_mutex_init(&data->logs[0], NULL);
}

/* initialzes the mutex to count all full philosophers */
void	init_full_philos_mutex(t_data *data)
{
	pthread_mutex_init(&data->full_philos_mutex[0], NULL);
}

/* initialzes the mutex to indicate the death of a philosopher */
void	init_dead_mutex(t_data *data)
{
	pthread_mutex_init(&data->dead_mutex[0], NULL);
}

/* initializes the mutex to which protects the philo's eating time */
void	init_eating_time_mutex(t_data *data)
{
	pthread_mutex_init(&data->eating_time_mutex[0], NULL);
}
