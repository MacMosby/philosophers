/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philos_living.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:17:51 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:17:53 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philos_living(t_data *data)
{
	int	one_dead;
	int	i;
	long int	t_diff;

	one_dead = 0;
	while (one_dead == 0 && *data->full < data->num_philos)
	{
		i = 0;
		while (i < data->num_philos)
		{
			t_diff = get_timestamp(data) - data->eating_time[i];
			if (t_diff > data->time_to_die * 1000 && *data->full < data->num_philos)
			{
				printf("full philos: %d\n", *data->full);
				printf("%ld %d died\n", get_timestamp(data), i + 1);
				one_dead = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}
