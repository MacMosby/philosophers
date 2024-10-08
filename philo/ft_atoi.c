/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:25:50 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/17 17:25:52 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* takes a string as argument and returns it as an integer */
int	ft_atoi(const char *s, int i, int res)
{
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 43)
		i++;
	while (s[i])
	{
		res *= 10;
		res += (int)s[i] - 48;
		i++;
	}
	return (res);
}
