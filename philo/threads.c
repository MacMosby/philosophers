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

/* creates one thread per philosopher to start the routine */
void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(data->philos[i]->thread, NULL,
				&routine, data->philos[i]) != 0)
		{
			clean_data(data);
			exit(2);
		}
		i++;
	}
}

/* waits for all the threads to finish their execution */
void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(*(data->philos[i]->thread), NULL) != 0)
		{
			clean_data(data);
			exit(3);
		}
		i++;
	}
}
