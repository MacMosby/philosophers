/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:11:28 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:11:31 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_threads(t_data *data)
{
	int	i;
	t_data	*args;

	data->threads = malloc(data->num_philos * sizeof(pthread_t));
	i = 0;
	while (i < data->num_philos)
	{
		args = malloc(sizeof(t_data));
		*args = *data;
		args->thread = i;
		if (pthread_create(&data->threads[i], NULL, &routine, args) != 0)
			return (1);
		printf("Thread %d started execution.\n", i + 1);
		i++;
	}
	return (0);
}
