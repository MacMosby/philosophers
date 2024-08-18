/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:59:13 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/27 20:59:15 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "philosophers.h"

void	init_philos(t_data *data)
{
	int	i;
	pthread_t	t = 0;

	data->threads = malloc(data->num_of_philos * sizeof(t_philo));
	i = 0;
	while (i < data->num_of_philos)
	{
		data->threads[i].alive = 1;
		data->threads[i].data = data;
		data->threads[i].data->philo = &data->threads[i];
		data->threads[i].eating_time = 0;
		data->threads[i].full = 0;
		data->threads[i].index = i;
		data->threads[i].times_eaten = 0;
		data->threads[i].thread = t;
		i++;
	}
} */
