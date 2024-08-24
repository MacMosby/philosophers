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

/* assigns the passed arguments to the data struct by using ft_atoi */
void	set_input(t_data *data)
{
	data->num_of_philos = ft_atoi(data->av[1], 0, 0, 0);
	if (data->num_of_philos < 2)
	{
		printf("At least two philosophers are needed.\n");
		clean_data(data);
		exit(0);
	}
	data->time_to_die = ft_atoi(data->av[2], 0, 0, 0);
	data->time_to_eat = ft_atoi(data->av[3], 0, 0, 0);
	data->time_to_sleep = ft_atoi(data->av[4], 0, 0, 0);
	if (data->ac == 6)
		data->num_of_must_eats = ft_atoi(data->av[5], 0, 0, 0);
	else
		data->num_of_must_eats = -1;
}

/* initialzes certain values inside philosopher struct in the beginning */
void	set_philo_values(t_philo *philo, int i)
{
	philo->index = i;
	philo->number = i + 1;
	philo->full = 0;
	philo->times_eaten = 0;
	philo->eating_time = 0;
	philo->sleep_count = 0;
}

/* initializes the memory and values for each philosopher */
void	init_philos(t_data *data, int i)
{
	data->philos = ft_calloc(data->num_of_philos, sizeof(t_philo *));
	if (!data->philos)
	{
		clean_data(data);
		exit(1);
	}
	while (i < data->num_of_philos)
	{
		data->philos[i] = ft_calloc(1, sizeof(t_philo));
		if (!data->philos[i])
		{
			clean_data(data);
			exit(2);
		}
		set_philo_values(data->philos[i], i);
		data->philos[i]->thread = ft_calloc(1, sizeof(pthread_t));
		if (!data->philos[i]->thread)
		{
			clean_data(data);
			exit(3);
		}
		data->philos[i]->data = data;
		i++;
	}
}

/* allocates and initializes all mutexes */
void	init_mutexes(t_data *data)
{
	init_forks_memory(data);
	init_logs_mutex_memory(data);
	init_full_philos_mutex_memory(data);
	init_dead_mutex_memory(data);
	init_eating_time_mutex_memory(data);
	init_philo_number_mutex_memory(data);
	init_forks(data);
	init_logs_mutex(data);
	init_full_philos_mutex(data);
	init_dead_mutex(data);
	init_eating_time_mutex(data);
	init_philo_number_mutex(data);
}

/* initalizes all data for the data struct */
void	init_data(t_data *data)
{
	data->full_philos = 0;
	data->dead = 0;
	data->secs = 0;
	data->msecs = 0;
	data->philos = NULL;
	data->forks = NULL;
	data->logs = NULL;
	data->dead_mutex = NULL;
	data->full_philos_mutex = NULL;
	data->philo_number_mutex = NULL;
	set_input(data);
	init_philos(data, 0);
	init_mutexes(data);
}
