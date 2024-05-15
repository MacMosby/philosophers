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

// FUNCTIONS NOT USED
	// memset
	// write
	// pthread_detach

// TO DO
	// keep track of the times inside the main thread and check if the smallest time is out of range
	// then call the philo dead and end the program

#include "philosophers.h"

long int get_timestamp(t_data *data)
{
	struct timeval	t;
	long int	secs;
	long int	msecs;

	gettimeofday(&t, NULL);
	secs = t.tv_sec - data->secs;
	msecs = t.tv_usec - data->msecs;
	msecs += secs * 1000000;
	return (msecs);
}

void	*routine(void *arg)
{
	t_data	*data = NULL;
	int	i;

	data = (t_data*)arg;
	if (data->thread % 2 == 1)
		usleep(data->time_to_eat / 2);
	i = 0;
	while (i != data->times_eating)
	{
		pthread_mutex_lock(&data->forks[data->thread]);
		printf("%ld %d has taken a fork\n", get_timestamp(data), data->thread + 1);
		pthread_mutex_lock(&data->forks[(data->thread + 1) % 8]);
		printf("%ld %d has taken a fork\n", get_timestamp(data), data->thread + 1);
		printf("%ld %d is eating\n", get_timestamp(data), data->thread + 1);
		data->eating_time[data->thread] = get_timestamp(data);
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&data->forks[data->thread]);
		pthread_mutex_unlock(&data->forks[(data->thread + 1) % 8]);
		printf("%ld %d is sleeping\n", get_timestamp(data), data->thread + 1);
		usleep(data->time_to_sleep * 1000);
		printf("%ld %d is thinking\n", get_timestamp(data), data->thread + 1);
		i++;
	}
	data->full += 1;
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

int	check_philos_living(t_data *data)
{
	int	one_dead;
	int	i;
	long int	t_diff;

	one_dead = 0;
	while (one_dead == 0 && data->full < 8)
	{
		i = 0;
		while (i < data->num_philos)
		{
			t_diff = get_timestamp(data) - data->eating_time[i];
			if (t_diff > 100)
			{
				printf("%ld %d died\n", get_timestamp(data), i + 1);
				one_dead = 1;
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	philo(t_data *data)
{
	struct timeval	t;
	if (data->num_philos == 1)
		printf("only one philosopher - nothing's gonna happen\n");
	else
	{
		init_eating_times(data);
		init_mutexes(data);
		gettimeofday(&t, NULL);
		data->secs = t.tv_sec;
		data->msecs = t.tv_usec;
		init_threads(data);
		if (check_philos_living(data) == 1)
		{
			// in case one dies I need to break all the other threads
			return (0);
		}
		join_threads(data);
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
