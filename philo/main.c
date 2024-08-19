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

// array of threads - num of philos ??? NO, an array of philos with one thread inside of the philo
// observe things from main thread ???
// mutex for get_timestamp ???

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

	data.ac = argc;
	data.av = argv;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		create_threads(&data);
		join_threads(&data);
		//clean_data(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
