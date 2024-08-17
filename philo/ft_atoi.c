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

int	ft_atoi(const char *s)
{
	int	i;
	int	res;
	int	minus;

	i = 0;
	res = 0;
	minus = 0;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 45)
	{
		minus = 1;
		i++;
	}
	else if (s[i] == 43)
		i++;
	while (s[i] > 47 && s[i] < 58)
	{
		res *= 10;
		res += (int)s[i] - 48;
		i++;
	}
	if (minus % 2 == 1)
		res *= (-1);
	return (res);
}
