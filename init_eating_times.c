/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_eating_times.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:16:34 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:16:36 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_eating_times(t_data *data)
{
	int	i;

	data->eating_time = malloc(data->num_philos * sizeof(long int));
	i = 0;
	while (i < data->num_philos)
	{
		data->eating_time[i] = 0;
		i++;
	}
}
