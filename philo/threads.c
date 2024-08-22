/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:22:30 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/21 14:22:31 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(data->philos[i]->thread, NULL, &routine, data->philos[i]) != 0)
			// EXIT HANDLE
			exit(2);
		printf("%ld Thread %d started execution.\n", get_timestamp(data),i + 1);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(*(data->philos[i]->thread), NULL) != 0)
			exit(3);
		//printf("%ld Thread %d finished execution.\n", get_timestamp(data),i + 1);
		i++;
	}
}
