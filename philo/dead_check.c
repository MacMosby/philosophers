/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:33:03 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/22 18:33:04 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* checks the passed time since each philosopher has started eating for the
last time and calls their death if it surpasses the time_to_die value */
void	dead_check(t_data *data, int i)
{
	long int	time_passed;

	while (++i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i]->p_mutex);
		time_passed = get_timestamp(data) - data->philos[i]->eating_time;
		pthread_mutex_unlock(data->philos[i]->p_mutex);
		if (time_passed > data->time_to_die * 1000)
		{
			pthread_mutex_lock(data->dead_mutex);
			if (data->dead == 0)
			{
				pthread_mutex_unlock(data->dead_mutex);
				pthread_mutex_lock(data->philos[i]->p_mutex);
				printf("%ld %d %s\n", get_timestamp(data) / 1000,
					data->philos[i]->number, DIED);
				pthread_mutex_unlock(data->philos[i]->p_mutex);
				pthread_mutex_lock(data->dead_mutex);
				data->dead = 1;
				pthread_mutex_unlock(data->dead_mutex);
			}
			else
				pthread_mutex_unlock(data->dead_mutex);
		}
	}
}
