/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:19:13 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:19:14 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo(t_data *data)
{
	struct timeval	t;
	if (data->num_philos == 1)
		printf("only one philosopher - nothing's gonna happen\n");
	else
	{
		data->full = malloc(sizeof(int));
		*data->full = 0;
		init_eating_times(data);
		init_mutexes(data);
		gettimeofday(&t, NULL);
		data->secs = t.tv_sec;
		data->msecs = t.tv_usec;
		init_threads(data);
		if (check_philos_living(data) == 1)
		{
			// in case one dies I need to break all the other threads
			return (0);
		}
		else
		{
			printf("everyone is full\n");
			return (0);
		}
		join_threads(data);
		destroy_mutexes(data);
	}
	return (0);
}
