/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:06:26 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/10 23:06:29 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_eating;
	int		thread;
	long int	secs;
	long int	msecs;
	long int	*eating_time;
	int		*full;
	pthread_t	*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t *full_philos;
}	t_data;

int	ft_atoi(const char *nptr);
long int get_timestamp(t_data *data);
int	init_threads(t_data *data);
int	join_threads(t_data *data);
int	init_mutexes(t_data *data);
int	destroy_mutexes(t_data *data);
void	init_eating_times(t_data *data);
int	check_philos_living(t_data *data);
int	philo(t_data *data);
void	*routine(void *arg);

#endif
