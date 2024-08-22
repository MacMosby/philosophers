/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:10:31 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/18 12:10:32 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* iterates over all philos and frees them one by one, first the philosopher's
thread, then the philosopher and lastly the array of philosophers */
void	clean_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		free(data->philos[i]->thread);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
}

/* destroys all mutexes and frees all memory related to the philosophers */
void	clean_data(t_data *data)
{
	destroy_mutexes(data);
	clean_philos(data);
}
