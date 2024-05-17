/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:20:38 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:20:40 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_data	*data = NULL;
	int	i;

	data = (t_data*)arg;
	if (data->thread % 2 == 1)
		usleep(data->time_to_eat / 2);
	i = 0;
	while (i != data->times_eating)
	{
		pthread_mutex_lock(&data->forks[data->thread]);
		printf("%ld %d has taken a fork\n", get_timestamp(data), data->thread + 1);
		pthread_mutex_lock(&data->forks[(data->thread + 1) % 8]);
		printf("%ld %d has taken a fork\n", get_timestamp(data), data->thread + 1);
		printf("%ld %d is eating\n", get_timestamp(data), data->thread + 1);
		data->eating_time[data->thread] = get_timestamp(data);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&data->forks[data->thread]);
		pthread_mutex_unlock(&data->forks[(data->thread + 1) % 8]);
		if (i + 1 == data->times_eating)
		{
			pthread_mutex_lock(&data->full_philos[0]);
			*data->full += 1;
			pthread_mutex_unlock(&data->full_philos[0]);
			return (NULL);
		}
		printf("%ld %d is sleeping\n", get_timestamp(data), data->thread + 1);
		usleep(data->time_to_sleep * 1000);
		printf("%ld %d is thinking\n", get_timestamp(data), data->thread + 1);
		i++;
	}
	printf("FULL: %d\n", *data->full);
	//free(arg);
	return (NULL);
}
