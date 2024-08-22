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
		printf("%ld mutex %d initialized\n", get_timestamp(data), i + 1);
		i++;
	}
}

void	init_logs_mutex(t_data *data)
{
	data->logs = malloc(sizeof(pthread_mutex_t));
	if (!data->logs)
		exit(1);
	pthread_mutex_init(&data->logs[0], NULL);
}

void	init_full_philos_mutex(t_data *data)
{
	data->full_philos_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->full_philos_mutex)
		exit(1);
	pthread_mutex_init(&data->full_philos_mutex[0], NULL);
}

void	init_dead_mutex(t_data *data)
{
	data->dead_mutex = malloc(sizeof(pthread_mutex_t));
	if (!data->dead_mutex)
		exit(1);
	pthread_mutex_init(&data->dead_mutex[0], NULL);
}

void	init_mutexes(t_data *data)
{
	init_forks(data);
	init_logs_mutex(data);
	init_full_philos_mutex(data);
	init_dead_mutex(data);
}
