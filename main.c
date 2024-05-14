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
// philos don't speak to each other
// philos don't know if another philo is about to die
// philos with even number start first, then uneven numbers with a small delay
// mallocs protecten
// mallocs freen
// how to track if someone starves and break the thread then without exit function ???

// how to pass (several) arguments to routine ???

#include "philosophers.h"

void	*routine(void *arg)
{
	t_data	*data = NULL;
	int	i;

	// ROUTINE
	// EAT, SLEEP, THINK - REPEAT
		// until philos are full or one dies
	sleep(1);
	data = (t_data*)arg;
	i = 0;
	while (i < data->times_eating)
	{
		// EATING
		pthread_mutex_lock(&data->forks[data->thread]);
		printf("timestamp_in_ms %d has taken a fork\n", data->thread + 1);
		pthread_mutex_lock(&data->forks[data->thread + 1]); // need to adjust for philo with number num_philos
		printf("timestamp_in_ms %d has taken a fork\n", data->thread + 1);
		printf("timestamp_in_ms %d is eating\n", data->thread + 1);
		// let time to eat run
		usleep(data->time_to_eat * 1000);
		pthread_mutex_unlock(&data->forks[data->thread]);
		pthread_mutex_unlock(&data->forks[data->thread + 1]); // need to adjust for philo with number num_philos
		// SLEEPING
		printf("timestamp_in_ms %d is sleeping\n", data->thread + 1);
		// let time to sleep run
		usleep(data->time_to_sleep * 1000);
		// THINKING
		printf("timestamp_in_ms %d is thinking\n", data->thread + 1);
			// go back to eating asap
		/* printf("philo %d iteration number %d\n", data->thread, i + 1);
		printf("num of philos: %d\n", data->thread); */
		i++;
	}
	sleep(1);
	printf("starting thread\n");
	sleep(3);
	printf("ending thread\n");
	sleep(1);
	//free(arg);
	return (NULL);
}

int	init_threads(t_data *data)
{
	int	i;

	data->threads = malloc(data->num_philos * sizeof(pthread_t));
	// PASSING THE STRUCT AFTER MALLOC A NEW VERSION OF IT SO THAT THE INDEX CANNOT CHANGE ???
	i = 0;
	while (i < data->num_philos)
	{
		t_data *args = malloc(sizeof(t_data));
		*args = *data;
		args->thread = i;
		/* int *num = malloc(sizeof(int));
		*num = i; */
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
		if (pthread_join(data->threads[i], NULL) != 0) // second argument is a pointer that takes the return from the thread
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
	if (argc == 5 || argc == 6)
	{
		t_data	data;
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
