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

/* allocates the memory for mutex which protects if all philos are full */
void	init_all_full_mutex_memory(t_data *data)
{
	data->all_full_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->all_full_mutex)
	{
		clean_data(data);
		exit(11);
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
