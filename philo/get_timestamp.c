/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:10:16 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/05/17 17:10:17 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	get_timestamp(t_data *data)
{
	struct timeval	t;
	long int		secs;
	long int		msecs;

	gettimeofday(&t, NULL);
	secs = t.tv_sec - data->secs;
	msecs = t.tv_usec - data->msecs;
	msecs += secs * 1000000;
	return (msecs);
}
