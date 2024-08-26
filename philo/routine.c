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

/* prints the logs for the change of the status of a philosopher and assigns
the new time of eating if a philosopher just started eating */
void	print_log(t_philo *philo, char *s)
{
	long int	time_stamp;

	pthread_mutex_lock(philo->data->logs);
	if (check_status(philo->data))
	{
		time_stamp = get_timestamp(philo->data);
		if (ft_strncmp(s, EAT, 9) == 0)
		{
			pthread_mutex_lock(philo->data->eating_time_mutex);
			philo->eating_time = get_timestamp(philo->data);
			pthread_mutex_unlock(philo->data->eating_time_mutex);
		}
		pthread_mutex_lock(philo->data->philo_number_mutex);
		printf("%ld %d %s\n", time_stamp / 1000, philo->number, s);
		pthread_mutex_unlock(philo->data->philo_number_mutex);
		pthread_mutex_unlock(philo->data->logs);
	}
	else
		pthread_mutex_unlock(philo->data->logs);
}

/* runs the eating routine by picking up two forks depending on the table
position */
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->index]);
	print_log(philo, FORK);
	pthread_mutex_lock(&philo->data->forks
	[(philo->index + 1) % philo->data->num_of_philos]);
	print_log(philo, FORK);
	print_log(philo, EAT);
	if (check_status(philo->data))
	{
		usleep(philo->data->time_to_eat * 1000);
		philo->times_eaten++;
	}
	pthread_mutex_unlock(&philo->data->forks[philo->index]);
	pthread_mutex_unlock(&philo->data->forks
	[(philo->index + 1) % philo->data->num_of_philos]);
}

/* runs the sleep routine */
void	ft_sleep(t_philo *philo)
{
	print_log(philo, SLEEP);
	if (check_status(philo->data))
		usleep(philo->data->time_to_sleep * 1000);
}

/* runs the think routine */
void	ft_think(t_philo *philo)
{
	print_log(philo, THINK);
}

/* runs the eat sleep think routine for each philosopher and increases
the number of full philosopher as soon as one has eaten the minimumamount
of times */
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 1 || philo->number == philo->data->num_of_philos)
		usleep(philo->data->time_to_eat * 1000 / 2);
	while (check_status(philo->data))
	{
		if (philo->data->num_of_philos > 1)
		{
			ft_eat(philo);
			if (philo->times_eaten == philo->data->num_of_must_eats)
			{
				pthread_mutex_lock(philo->data->full_philos_mutex);
				pthread_mutex_lock(philo->p_mutex);
				philo->full = 1;
				pthread_mutex_unlock(philo->p_mutex);
				pthread_mutex_unlock(philo->data->full_philos_mutex);
			}
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (NULL);
}
