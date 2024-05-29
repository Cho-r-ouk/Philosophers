/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 09:59:52 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	sem_wait(p->data->time);
	while (ft_time() < time)
	{
		if (p && p->data->is_dead)
			return (ft_print(p, "is dead"));
		usleep(10);
	}
	sem_post(p->data->time);
	return (0);
}

void	ft_free_data(t_data *d)
{
	sem_close(d->lock);
	sem_close(d->clock);
	sem_close(d->eat);
	sem_close(d->dead);
	sem_close(d->meal);
	sem_unlink("/forks");
	sem_unlink("/eat");
	sem_unlink("/meal");
	sem_unlink("/dead");
	sem_unlink("/lock");
	sem_unlink("/clock");
}
