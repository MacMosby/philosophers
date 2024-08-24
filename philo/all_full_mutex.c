/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_full_mutex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 12:03:29 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/24 12:03:31 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* initializes the mutex which protects if all philos are full */
void	init_all_full_mutex(t_data *data)
{
	pthread_mutex_init(&data->all_full_mutex[0], NULL);
}

/* allocates the memory for mutex which protects if all philos are full */
void	init_all_full_mutex_memory(t_data *data)
{
	data->all_full_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->all_full_mutex)
	{
		clean_data(data);
		exit(10);
	}
}

/* destroys the mutex to protect the philo's number */
void	destroy_all_full_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->all_full_mutex[0]);
}
