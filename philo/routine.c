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
	// print log
	printf("%ld %d %s\n", get_timestamp(philo->data),philo->number, s);
	pthread_mutex_unlock(philo->data->logs);
}

void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 1)
		usleep(philo->data->time_to_eat * 1000 / 2);
	// while condition needs to be changed
	// as long as all philos alive and this one not full yet
	//while (philo->times_eaten != philo->data->num_of_must_eats && philo->alive)
	while (1)
	{
		// pick up first fork available
		pthread_mutex_lock(&philo->data->forks[philo->index]);
		print_log(philo, FORK);
		// pick up second fork available
		pthread_mutex_lock(&philo->data->forks[(philo->index + 1) % 8]);
		print_log(philo, FORK);
		// eat for x milliseconds
		print_log(philo, EAT);
		usleep(philo->data->time_to_eat * 1000);
		philo->times_eaten++;
		if (philo->times_eaten != philo->data->num_of_must_eats)
			// sleep for x milliseconds
			print_log(philo, SLEEP);
		// put down both forks
		pthread_mutex_unlock(&philo->data->forks[philo->index]);
		pthread_mutex_unlock(&philo->data->forks[(philo->index + 1) % 8]);
		if (philo->times_eaten == philo->data->num_of_must_eats)
		{
			pthread_mutex_lock(philo->data->full_philos_mutex);
			philo->data->full_philos += 1;
			pthread_mutex_unlock(philo->data->full_philos_mutex);
			break;
		}
		// sleep for x milliseconds
		usleep(philo->data->time_to_sleep * 1000);
		// think for only one moment and repeat the routine
		print_log(philo, THINK);
	}
	return (NULL);
}
