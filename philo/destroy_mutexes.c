/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:26:53 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/21 14:26:55 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

void	destroy_logs_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->logs[0]);
	free(data->logs);
}

void	destroy_full_philos_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->full_philos_mutex[0]);
	free(data->full_philos_mutex);
}

void	destroy_dead_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->dead_mutex[0]);
	free(data->dead_mutex);
}

void	destroy_mutexes(t_data *data)
{
	destroy_forks(data);
	destroy_logs_mutex(data);
	destroy_full_philos_mutex(data);
	destroy_dead_mutex(data);
}
