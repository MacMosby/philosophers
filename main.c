/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:07:59 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/10 23:08:00 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// simulation ends when a philo dies of starvation OR they've had enough food
// mallocs protecten
// mallocs freen
// how to track if someone starves and break the thread then without exit function ???
// timestamps !!!

// FUNCTIONS NOT USED
	// memset
	// write
	// gettimeofday
	// pthread_detach

#include "philosophers.h"

void	*routine(void *arg)
{
	t_data	*data = NULL;
	int	i;

	data = (t_data*)arg;
	if (data->thread % 2 == 1)
		usleep(data->time_to_eat / 2);
	i = 0;
	while (i < data->times_eating)
	{
		pthread_mutex_lock(&data->forks[data->thread]);
		printf("timestamp_in_ms %d has taken a fork\n", data->thread + 1);
		pthread_mutex_lock(&data->forks[data->thread + 1]); // need to adjust for philo with number num_philos
		printf("timestamp_in_ms %d has taken a fork\n", data->thread + 1);
		printf("timestamp_in_ms %d is eating\n", data->thread + 1);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&data->forks[data->thread]);
		pthread_mutex_unlock(&data->forks[data->thread + 1]); // need to adjust for philo with number num_philos
		printf("timestamp_in_ms %d is sleeping\n", data->thread + 1);
		usleep(data->time_to_sleep * 1000);
		printf("timestamp_in_ms %d is thinking\n", data->thread + 1);
		i++;
	}
	//free(arg);
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;
	t_data	*args;

	data->threads = malloc(data->num_philos * sizeof(pthread_t));
	i = 0;
	while (i < data->num_philos)
	{
		args = malloc(sizeof(t_data));
		*args = *data;
		args->thread = i;
		if (pthread_create(&data->threads[i], NULL, &routine, args) != 0)
			return (1);
		printf("Thread %d started execution.\n", i + 1);
		i++;
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
		{
			return (2);
		}
		printf("Thread %d finished execution.\n", i + 1);
		i++;
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	data->forks = malloc(data->num_philos * sizeof(pthread_mutex_t));
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		printf("mutex %d initialized\n", i + 1);
		i++;
	}
	return (0);
}

int	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		printf("mutex %d destroyed\n", i + 1);
		i++;
	}
	return (0);
}

int	philo(t_data *data)
{
	if (data->num_philos == 1)
		printf("only one philosopher - nothing's gonna happen\n");
	else
	{
		// initialize forks/mutexes
		init_mutexes(data);
		// initialize threads
		init_threads(data);
		// join threads
		join_threads(data);
		// destroy mutexes
		destroy_mutexes(data);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		data.num_philos = ft_atoi(argv[1]);
		data.time_to_die = ft_atoi(argv[2]);
		data.time_to_eat = ft_atoi(argv[3]);
		data.time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data.times_eating = ft_atoi(argv[5]);
		else
			data.times_eating = -1;
		philo(&data);
	}
	else
	{
		printf("wrong input\n");
	}
	return (0);
}
