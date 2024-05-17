/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:14:19 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:14:22 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_mutexes(t_data *data)
{
	int	i;

	data->full_philos = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->full_philos[0], NULL);
	data->forks = malloc(data->num_philos * sizeof(pthread_mutex_t));
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		printf("mutex %d initialized\n", i + 1);
		i++;
	}
	return (0);
}
