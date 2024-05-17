/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:15:22 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:15:24 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy_mutexes(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->full_philos[0]);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		printf("mutex %d destroyed\n", i + 1);
		i++;
	}
	return (0);
}
