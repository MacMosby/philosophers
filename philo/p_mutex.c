/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_mutex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:05:12 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/24 18:05:13 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_p_mutex(t_data *data, int i)
{
	data->philos[i]->p_mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!data->philos[i]->p_mutex)
	{
		clean_data(data);
		exit(3);
	}
	pthread_mutex_init(&data->philos[i]->p_mutex[0], NULL);
}

/* destroys the mutex to indicate the death of a philosopher & frees the
allocated memory */
void	destroy_p_mutex(t_data *data, int i)
{
	pthread_mutex_destroy(&data->philos[i]->p_mutex[0]);
}
