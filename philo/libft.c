/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:22 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/01/30 13:28:14 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (*(src + i) && --n)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}

int	ft_atoi(char *str)
{
	long		n;

	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		(str)++;
	if (*str == '+')
		(str)++;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while ((*str >= '0' && *str <= '9'))
	{
		n = n * 10 + *str - '0';
		if (n < INT_MIN || n > INT_MAX)
			return (0);
		str++;
	}
	return (n);
}
