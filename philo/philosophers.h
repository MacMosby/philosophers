/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:50:20 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/17 15:50:22 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// MAKROS
# define FORK "has taken fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

// LIBRARIES
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

//STRUCTS

typedef struct s_data
{
	int		ac;
	char	**av;
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_must_eats;
	struct s_philo *philos;
	pthread_t *threads;
	pthread_mutex_t *forks;
	pthread_mutex_t	*logs;
	pthread_mutex_t *full_philos;
}	t_data;

typedef struct s_philo
{
	int	index;
	int	number;
	int	alive;
	int	full;
	int	times_eaten;
	long int	eating_time;
	t_data	*data;
	pthread_t	thread;
}	t_philo;

// FUNCTIONS

// clean_data.c
void	clean_data(t_data *data);

// ft_atoi.c
int		ft_atoi(const char *s);

// init_data.c
void	init_data(t_data *data);

// routine.c
void	*routine(void *arg);

#endif
