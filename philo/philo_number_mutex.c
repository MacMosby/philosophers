/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_number_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 10:25:49 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/24 10:25:50 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* initializes the mutex to which protects the philo's number */
void	init_philo_number_mutex(t_data *data)
{
	pthread_mutex_init(&data->philo_number_mutex[0], NULL);
}

/* allocates the memory for mutex which protects the philo's number */
void	init_philo_number_mutex_memory(t_data *data)
{
	data->philo_number_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->philo_number_mutex)
	{
		clean_data(data);
		exit(10);
	}
}

/* destroys the mutex to protect the philo's number */
void	destroy_philo_number_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->philo_number_mutex[0]);
}
