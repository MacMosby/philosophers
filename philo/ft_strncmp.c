/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodenbu <mrodenbu@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:27:25 by mrodenbu          #+#    #+#             */
/*   Updated: 2023/06/26 15:38:07 by mrodenbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& i < n && (unsigned char)s1[i] != '\0'
		&& (unsigned char)s2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
