/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:10:31 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/18 12:10:32 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_forks(t_data *data)
{
	// need to free ???
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		printf("mutex %d destroyed\n", i + 1);
		i++;
	}
}

void	destroy_logs_mutex(t_data *data)
{
	// need to free ???
	pthread_mutex_destroy(&data->logs[0]);
}

void	destroy_full_philos_mutex(t_data *data)
{
	// need to free ???
	pthread_mutex_destroy(&data->full_philos[0]);
}

void	destroy_mutexes(t_data *data)
{
	destroy_forks(data);
	destroy_logs_mutex(data);
	destroy_full_philos_mutex(data);
}

void	clean_data(t_data *data)
{
	destroy_mutexes(data);
}
