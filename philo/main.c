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

#include "philosophers.h"

void	all_full(t_data *data)
{
	int	i;

	i = 0;
	data->full_philos = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(data->philos[i]->p_mutex);
		if (data->philos[i]->full)
		{
			pthread_mutex_unlock(data->philos[i]->p_mutex);
			data->full_philos += 1;
			if (data->full_philos == data->num_of_philos)
				data->all_full = 1;
		}
		else
		{
			pthread_mutex_unlock(data->philos[i]->p_mutex);
			break ;
		}
		i++;
	}
}

/* checks number of passed arguments and monitors the running simulation for
a philosopher dying and philosophers being full */
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
			dead_check(&data, -1);
			all_full(&data);
			if (check_status(&data) == 0)
			{
				break ;
			}
		}
		join_threads(&data);
		destroy_mutexes(&data);
		clean_data(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
