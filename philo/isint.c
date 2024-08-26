/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 10:21:53 by mrodenbu          #+#    #+#             */
/*   Updated: 2024/08/26 10:21:55 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/* takes a string as argument and returns it as a long long int */
long long int	ft_atoll(const char *s)
{
	int				i;
	long long int	res;

	i = 0;
	res = 0;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 43)
		i++;
	while (s[i])
	{
		if (!(ft_isdigit((long long int)s[i])))
		{
			printf("Wrong input - not a valid number!\n");
			exit(14);
		}
		res *= 10;
		res += (long long int)s[i] - 48;
		i++;
	}
	printf("test number: %lld\n", res);
	return (res);
}

int	isint(char *str)
{
	long long int	num;

	if (ft_strlen(str) > 10)
	{
		printf("Wrong input - not a valid number!\n");
		exit(15);
	}
	num = ft_atoll(str);
	printf("test number: %lld\n", num);
	if (num <= (long long int)2147483647)
		return (1);
	printf("Wrong input - not a valid number!\n");
	exit(16);
}
