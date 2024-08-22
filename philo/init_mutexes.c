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

	data->forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		exit(1);
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
	data->logs = malloc(sizeof(pthread_mutex_t));
	if (!data->logs)
		exit(1);
	pthread_mutex_init(&data->logs[0], NULL);
}

/* initialzes the mutex to count all full philosophers */
void	init_full_philos_mutex(t_data *data)
{
	data->full_philos_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->full_philos_mutex)
		exit(1);
	pthread_mutex_init(&data->full_philos_mutex[0], NULL);
}

/* initialzes the mutex to indicate the death of a philosopher */
void	init_dead_mutex(t_data *data)
{
	data->dead_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->dead_mutex)
		exit(1);
	pthread_mutex_init(&data->dead_mutex[0], NULL);
}

/* initializes all mutexes */
void	init_mutexes(t_data *data)
{
	init_forks(data);
	init_logs_mutex(data);
	init_full_philos_mutex(data);
	init_dead_mutex(data);
}
