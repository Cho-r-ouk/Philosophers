/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:40 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init(t_data *d)
{
	int	i;

	if (pthread_mutex_init(&d->lock, NULL))
		return (0);
	if (pthread_mutex_init(&d->check, NULL))
		return (0);
	if (pthread_mutex_init(&d->dead, NULL))
		return (0);
	if (pthread_mutex_init(&d->count, NULL))
		return (0);
	d->start_time = ft_time();
	d->is_dead = 0;
	d->start = 0;
	i = -1;
	while (++i < d->tab[0])
	{
		d->philo[i].id = i + 1;
		d->philo[i].data = d;
		d->philo[i].eat_count = 0;
		d->philo[i].last_meal = d->start_time;
	}
	return (1);
}

int	ft_destroy(t_data *d)
{
	if (pthread_mutex_destroy(&d->lock))
		return (0);
	if (pthread_mutex_destroy(&d->check))
		return (0);
	if (pthread_mutex_destroy(&d->dead))
		return (0);
	if (pthread_mutex_destroy(&d->count))
		return (0);
	return (1);
}

int	ft_philo(t_data *d)
{
	int			i;
	pthread_t	check;

	if (!ft_fork(d))
		return (0);
	i = -1;
	if (!ft_init(d))
		return (0);
	while (++i < d->tab[0])
		if (pthread_create(&d->philo[i].philo, NULL, &ft_action,
				(void *)&d->philo[i]))
			return (write(2, "error creating thread\n", 23), 0);
	(ft_set_start(d), i = -1);
	if (pthread_create(&check, NULL, &ft_check, d))
		return (write(2, "error creating thread\n", 23), 0);
	if (pthread_join(check, NULL))
		return (write(2, "error joining thread\n", 22), 0);
	while (++i < d->tab[0])
		if (pthread_join(d->philo[i].philo, NULL))
			return (write(2, "error joining thread\n", 22), 0);
	ft_free_data(d);
	if (!ft_destroy(d))
		return (0);
	return (1);
}
