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

// when philo full, should they still go to sleep and think until all of them are full ???

#include "philosophers.h"

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
