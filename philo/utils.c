/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:20:30 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (write(2, "error getting time\n", 20), 0);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_sleep(t_philo *p, long t)
{
	long	time;

	time = ft_time() + t;
	while (ft_time() < time)
	{
		if (p && ft_dead(p->data))
			return (ft_print(p, "is dead"));
		usleep(100);
	}
	return (0);
}

void	ft_free_data(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->tab[0])
	{
		pthread_mutex_unlock(&d->philo[i].fork_l);
		pthread_mutex_destroy(&d->philo[i].fork_l);
		i++;
	}
}
