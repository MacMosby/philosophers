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

/* iterates over all philos and frees them one by one, first the philosopher's
thread, then the philosopher and lastly the array of philosophers */
void	clean_philos(t_data *data)
{
	int	i;

	i = 0;
	if (!data->philos)
		return ;
	while (i < data->num_of_philos)
	{
		if (data->philos[i])
		{
			if (data->philos[i]->thread)
				free(data->philos[i]->thread);
			free(data->philos[i]);
		}
		i++;
	}
	free(data->philos);
}

/* frees memory allocated for the mutexes */
void	clean_mutexes(t_data *data)
{
	if (data->forks)
		free(data->forks);
	if (data->logs)
		free(data->logs);
	if (data->all_full_mutex)
		free(data->all_full_mutex);
	if (data->dead_mutex)
		free(data->dead_mutex);
	if (data->full_philos_mutex)
		free(data->full_philos_mutex);
	if (data->eating_time_mutex)
		free(data->eating_time_mutex);
	if (data->philo_number_mutex)
		free(data->philo_number_mutex);
}

/* destroys all mutexes and frees all memory related to the philosophers */
void	clean_data(t_data *data)
{
	clean_philos(data);
	clean_mutexes(data);
}
