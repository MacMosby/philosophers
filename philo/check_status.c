/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:33:55 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/21 16:33:57 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_data *data)
{
	pthread_mutex_lock(data->dead_mutex);
	if (data->dead)
	{
		pthread_mutex_unlock(data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->dead_mutex);
	return (0);
}

int	check_all_full(t_data *data)
{
	pthread_mutex_lock(data->full_philos_mutex);
	if (data->full_philos == data->num_of_philos)
	{
		//printf("TESTETSTETSTETST\n");
		pthread_mutex_unlock(data->full_philos_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->full_philos_mutex);
	return (0);
}

int	check_status(t_data *data)
{
	if (check_dead(data))
		return (0);
	if (check_all_full(data))
		return (0);
	return (1);
}
