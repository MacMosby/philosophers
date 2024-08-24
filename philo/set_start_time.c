/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:30:06 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/27 19:30:08 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* sets the starting time for the simulation & assigns it to all philosophers */
void	set_start_time(t_data *data)
{
	struct timeval	t;
	int				i;
	long int		time;

	gettimeofday(&t, NULL);
	data->secs = t.tv_sec;
	data->msecs = t.tv_usec;
	time = (1000000 * data->secs) + data->msecs;
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(data->eating_time_mutex);
		data->philos[i]->eating_time = get_timestamp(data);
		pthread_mutex_unlock(data->eating_time_mutex);
		i++;
	}
}
