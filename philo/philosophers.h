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
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

//STRUCTS

typedef struct s_data
{
	int				ac;
	char			**av;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eats;
	int				full_philos;
	int				dead;
	long int		secs;
	long int		msecs;
	struct s_philo	**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*logs;
	pthread_mutex_t	*full_philos_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*eating_time_mutex;
}	t_data;

typedef struct s_philo
{
	int			index;
	int			number;
	int			full;
	int			times_eaten;
	long int	eating_time;
	int			sleep_count;
	pthread_t	*thread;
	t_data		*data;
}	t_philo;

// FUNCTIONS

// check_status.c
int			check_status(t_data *data);

// clean_data.c
void		clean_data(t_data *data);

// dead_check.c
int			dead_check(t_data *data, int i);

// destroy_mutexes.c
void		destroy_mutexes(t_data *data);

// ft_atoi.c
int			ft_atoi(const char *s, int i, int res, int minus);

// ft_calloc.c
void		*ft_calloc(size_t nmemb, size_t size);

// ft_isdigit.c
int			ft_isdigit(int s);

// ft_strncmp.c
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// get_timestamp.c
long int	get_timestamp(t_data *data);

// init_data.c
void		init_data(t_data *data);

// init_mutex_memory.c
void		init_forks_memory(t_data *data);
void		init_logs_mutex_memory(t_data *data);
void		init_full_philos_mutex_memory(t_data *data);
void		init_dead_mutex_memory(t_data *data);
void		init_eating_time_mutex_memory(t_data *data);

// init_mutexes.c
void		init_forks(t_data *data);
void		init_logs_mutex(t_data *data);
void		init_full_philos_mutex(t_data *data);
void		init_dead_mutex(t_data *data);
void		init_eating_time_mutex(t_data *data);

// routine.c
void		print_log(t_philo *philo, char *s);
void		*routine(void *arg);

// set_start_time.c
void		set_start_time(t_data *data);

// threads.c
void		create_threads(t_data *data);
void		join_threads(t_data *data);

#endif
