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

// LIBRARIES
# include <stdlib.h>
# include <stdio.h>
//# include <unistd.h>
# include <pthread.h>

// FUNCTIONS
// ft_atoi.c
int	ft_atoi(const char *s);

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
}	t_data;


#endif
