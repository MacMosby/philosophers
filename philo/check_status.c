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

/* checks if at least one philosopher has died and returns value 1 (yes) or 0
(no) accordingly */
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

/* checks if all philosopher have eaten at least the minimum amount of times
and returns 1 (yes) or 0 (no) accordingly */
int	check_all_full(t_data *data)
{
	pthread_mutex_lock(data->all_full_mutex);
	if (data->all_full == 1)
	{
		pthread_mutex_unlock(data->all_full_mutex);
		return (1);
	}
	pthread_mutex_unlock(data->all_full_mutex);
	return (0);
}

/* checks if all philos are still alive and at least one still needs to eat
and returns 1 (yes) or 0 (no) accordingly */
int	check_status(t_data *data)
{
	if (check_dead(data))
		return (0);
	if (check_all_full(data))
		return (0);
	return (1);
}
