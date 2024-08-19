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

void	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(data->philos[i]->thread, NULL, &routine, data->philos[i]) != 0)
			exit(2);
		printf("Thread %d started execution.\n", i + 1);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_join(*(data->philos[i]->thread), NULL) != 0)
			exit(3);
		printf("Thread %d finished execution.\n", i + 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	data.ac = argc;
	data.av = argv;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		set_start_time(&data);
		create_threads(&data);
		while (1)
		{
			i = 0;
			// if one dies, stop all threads and break the loop
			while (i < data.num_of_philos)
			{
				if (!data.philos[i]->alive)
				{
					print_log(data.philos[i], DIED);
					break;
				}
				i++;
			}
			// if all philos are full break out of the loop and exit clean (return(0);)
			if (data.full_philos == data.num_of_philos)
				break;
		}
		join_threads(&data);
		//clean_data(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
