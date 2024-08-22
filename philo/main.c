/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:33:52 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/17 15:33:54 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TO DO
- run check inside routine if philo dies and set flag alive to 0
*/

#include "philosophers.h"

int	someone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (get_timestamp(data) - data->philos[i]->eating_time > data->time_to_die)
		{
			pthread_mutex_lock(data->dead_mutex);
			if (data->dead == 0)
			{
				print_log(data->philos[i], DIED);
				data->dead = 1;
				pthread_mutex_unlock(data->dead_mutex);
				return (1);
			}
			else
				pthread_mutex_unlock(data->dead_mutex);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.ac = argc;
	data.av = argv;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		set_start_time(&data);
		create_threads(&data);
		while (1)
		{
			// if one dies, stop all threads and break the loop
			if (someone_dead(&data) || check_status(&data) == 0)
			{
				printf("WHATEVER\n");
				break;
			}
		}
		printf("WE'RE DONE!!!\n");
		join_threads(&data);
		clean_data(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
