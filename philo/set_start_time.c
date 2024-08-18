/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 19:30:06 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/27 19:30:08 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_start_time(t_data *data)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	data->secs = t.tv_sec;
	data->msecs = t.tv_usec;
}
