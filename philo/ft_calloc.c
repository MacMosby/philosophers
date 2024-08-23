/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:08:16 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/06/28 16:08:55 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* allocates memory and initializes it with zeros */
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		while (i < nmemb * size)
		{
			ptr[i] = 0;
			i++;
		}
		return ((void *)ptr);
	}
}
