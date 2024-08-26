/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:04:19 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/23 13:04:20 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* allocates memory for the forks' mutexes */
void	init_forks_memory(t_data *data)
{
	data->forks = ft_calloc(data->num_of_philos, sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		clean_data(data);
		exit(5);
	}
}

/* allocates the memory for the logs mutex */
void	init_logs_mutex_memory(t_data *data)
{
	data->logs = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->logs)
	{
		clean_data(data);
		exit(6);
	}
}

/* allocates memory for the mutex to protect the number of full philos */
void	init_full_philos_mutex_memory(t_data *data)
{
	data->full_philos_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->full_philos_mutex)
	{
		clean_data(data);
		exit(7);
	}
}

/* allocates the memory for the indicator of a philo dying */
void	init_dead_mutex_memory(t_data *data)
{
	data->dead_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->dead_mutex)
	{
		clean_data(data);
		exit(8);
	}
}

/* allocates the memory for mutex which protects the philo's eating time */
void	init_eating_time_mutex_memory(t_data *data)
{
	data->eating_time_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->eating_time_mutex)
	{
		clean_data(data);
		exit(9);
	}
}
