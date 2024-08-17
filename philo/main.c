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

// WHAT I NEED ???
// array of threads
// array of mutexes for forks
// one mutex for print statements to not mix them up
// observe things from main thread ???

void	*routine(void *arg)
{
	arg = NULL;
	printf("Test from thread number: \n");
	// pick up first fork available
	// pick up second fork available
	// eat for x milliseconds
	// put down both forks
	// sleep for x milliseconds
	// think for only one moment and repeat the routine
	return (NULL);
}

void	init_data(t_data *data)
{
	data->num_of_philos = ft_atoi(data->av[1]);
	if (data->num_of_philos < 2)
	{
		printf("At least two philosophers are needed.\n");
		exit(1);
	}
	data->time_to_die = ft_atoi(data->av[2]);
	data->time_to_eat = ft_atoi(data->av[3]);
	data->time_to_sleep = ft_atoi(data->av[4]);
	if (data->ac == 6)
		data->num_of_must_eats = ft_atoi(data->av[5]);
	else
		data->num_of_must_eats = -1;
	printf("num of philos: %d\n", data->num_of_philos);
	printf("time to die: %d ms\n", data->time_to_die);
	printf("time to eat: %d ms\n", data->time_to_eat);
	printf("time to sleep: %d ms\n", data->time_to_sleep);
	printf("num of must eats: %d\n", data->num_of_must_eats);
}

void	init_threads(t_data *data)
{
	pthread_t	t1;
	data->ac += 0;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		exit(1);
	if (pthread_join(t1, NULL) != 0)
		exit(2);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.ac = argc;
	data.av = argv;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		init_threads(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
