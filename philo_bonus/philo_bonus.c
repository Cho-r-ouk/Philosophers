/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/30 08:33:13 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_open(t_data *d)
{
	ft_unlink();
	d->forks = sem_open("/forks", O_CREAT, 0644, d->tab[0]);
	if (d->forks == SEM_FAILED)
		return (0);
	d->eat = sem_open("/eat", O_CREAT, 0644, 1);
	if (d->eat == SEM_FAILED)
		return (0);
	d->time = sem_open("/time", O_CREAT, 0644, 1);
	if (d->time == SEM_FAILED)
		return (0);
	d->meal = sem_open("/meal", O_CREAT, 0644, 1);
	if (d->meal == SEM_FAILED)
		return (0);
	d->dead = sem_open("/dead", O_CREAT, 0644, 1);
	if (d->dead == SEM_FAILED)
		return (0);
	d->lock = sem_open("/lock", O_CREAT, 0644, 1);
	if (d->lock == SEM_FAILED)
		return (0);
	d->clock = sem_open("/clock", O_CREAT, 0644, 1);
	if (d->clock == SEM_FAILED)
		return (0);
	return (1);
}

static int	ft_init(t_data *d)
{
	int	i;

	i = -1;
	d->start = 0;
	d->is_dead = 0;
	d->start_time = ft_time();
	while (++i < d->tab[0])
	{
		d->philo.id = i + 1;
		d->philo.data = d;
		d->philo.eat_count = 0;
		d->philo.pid = fork();
		if (d->philo.pid == -1)
			return (write(2, "error creating process\n", 24),
				kill(d->philo.pid, 13), 0);
		d->philo.last_meal = d->start_time;
		if (d->philo.pid == 0)
			if (!ft_action(&d->philo))
				return (kill(d->philo.pid, 13), 0);
	}
	if (waitpid(0, 0, 0) == -1)
		return (0);
	return (1);
}

int	ft_philo(t_data *d)
{
	if (!ft_open(d))
		return (ft_close(d), 0);
	if (!ft_init(d))
		return (ft_close(d), 0);
	ft_close(d);
	return (1);
}
