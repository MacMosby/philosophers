/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 12:08:14 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/18 12:08:16 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_input(t_data *data)
{
	data->num_of_philos = ft_atoi(data->av[1]);
	if (data->num_of_philos < 2)
	{
		printf("At least two philosophers are needed.\n");
		// EXIT HANDLE
		exit(1);
	}
	data->time_to_die = ft_atoi(data->av[2]);
	data->time_to_eat = ft_atoi(data->av[3]);
	data->time_to_sleep = ft_atoi(data->av[4]);
	if (data->ac == 6)
		data->num_of_must_eats = ft_atoi(data->av[5]);
	else
		data->num_of_must_eats = -1;
}

void	init_threads(t_data *data)
{
	data->threads = malloc(data->num_of_philos * sizeof(pthread_t));
	if (!data->threads)
		// EXIT HANDLE
		exit(1);
}

void	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		// EXIT HANDLE
		exit(1);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		printf("mutex %d initialized\n", i + 1);
		i++;
	}
}

void	init_logs_mutex(t_data *data)
{
	data->logs = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->logs[0], NULL);
}

void	init_full_philos_mutex(t_data *data)
{
	data->full_philos = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->full_philos[0], NULL);
}

void	init_mutexes(t_data *data)
{
	init_forks(data);
	init_logs_mutex(data);
	init_full_philos_mutex(data);
}

void	init_data(t_data *data)
{
	set_input(data);
	init_threads(data); // init philos instead ??
	init_mutexes(data);
}
