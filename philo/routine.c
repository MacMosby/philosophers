/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 11:52:08 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/18 11:52:09 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_log(t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->data->logs);
	if (check_status(philo->data))
	{
		printf("%ld %d %s\n", get_timestamp(philo->data),philo->number, s);
		pthread_mutex_unlock(philo->data->logs);
	}
	else
		pthread_mutex_unlock(philo->data->logs);
}

void	ft_eat(t_philo *philo)
{
	// pick up first fork
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->data->forks[philo->index]);
	else
		pthread_mutex_lock(&philo->data->forks[(philo->index + 1) % 8]);
	print_log(philo, FORK);
	// pick up second fork
	if (philo->index % 2 == 0)
		pthread_mutex_lock(&philo->data->forks[(philo->index + 1) % 8]);
	else
		pthread_mutex_lock(&philo->data->forks[philo->index]);
	print_log(philo, FORK);
	// eat for x milliseconds
	print_log(philo, EAT);
	if (check_status(philo->data))
	{
		usleep(philo->data->time_to_eat * 1000);
		philo->times_eaten++;
	}
	// put down both forks
	pthread_mutex_unlock(&philo->data->forks[philo->index]);
	pthread_mutex_unlock(&philo->data->forks[(philo->index + 1) % 8]);
}

void	ft_sleep(t_philo *philo)
{
	// sleep for x milliseconds
	print_log(philo, SLEEP);
	// sleep for x milliseconds
	if (check_status(philo->data))
		usleep(philo->data->time_to_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	// think for only one moment and repeat the routine
	print_log(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 1)
		usleep(philo->data->time_to_eat * 1000 / 2);
	while (check_status(philo->data))
	{
		ft_eat(philo);
		if (philo->times_eaten == philo->data->num_of_must_eats)
		{
			pthread_mutex_lock(philo->data->full_philos_mutex);
			philo->data->full_philos += 1;
			printf("Philo %d is full\n", philo->number);
			printf("%d philos are full\n", philo->data->full_philos);
			pthread_mutex_unlock(philo->data->full_philos_mutex);
		}
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
