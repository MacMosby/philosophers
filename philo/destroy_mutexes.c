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

/* destroys all fork mutexes and frees the allocated memory */
void	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

/* destroys the mutex for the printing function & frees the allocated memory */
void	destroy_logs_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->logs[0]);
}

/* destroys the mutex to count full philosophers & frees the allocated memory */
void	destroy_full_philos_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->full_philos_mutex[0]);
}

/* destroys the mutex to indicate the death of a philosopher & frees the
allocated memory */
void	destroy_dead_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->dead_mutex[0]);
}

/* destroy all mutexes by calling several destroy_mutex functions */
void	destroy_mutexes(t_data *data)
{
	int	i;

	destroy_forks(data);
	destroy_logs_mutex(data);
	destroy_all_full_mutex(data);
	destroy_dead_mutex(data);
	destroy_full_philos_mutex(data);
	destroy_eating_time_mutex(data);
	destroy_philo_number_mutex(data);
	i = 0;
	while (i < data->num_of_philos)
	{
		destroy_p_mutex(data, i);
		i++;
	}
}
