/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 15:33:52 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/17 15:33:54 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
TO DO
- check for data races and race conditions --> helgrind
- norminette
- comment on all functions as description
*/

#include "philosophers.h"

/* checks number of passed arguments and monitors the running simulation for
a philosopher dying and philosophers being full */
int	main(int argc, char **argv)
{
	t_data	data;

	data.ac = argc;
	data.av = argv;
	if (argc == 5 || argc == 6)
	{
		init_data(&data);
		set_start_time(&data);
		create_threads(&data);
		while (1)
		{
			if (dead_check(&data) || check_status(&data) == 0)
			{
				break ;
			}
		}
		join_threads(&data);
		destroy_mutexes(&data);
		clean_data(&data);
	}
	else
		printf("Wrong number of arguments - Byyyyyyyyeeeeeee!\n");
	return (0);
}
