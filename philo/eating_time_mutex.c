/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_time_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:39:12 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/24 13:39:13 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* destroys the mutex to indicate the death of a philosopher & frees the
allocated memory */
void	destroy_eating_time_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->eating_time_mutex[0]);
}
