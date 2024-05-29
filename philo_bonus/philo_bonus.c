/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 15:42:56 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_init_fork(t_data *d)
{
	sem_unlink("/forks");
	sem_unlink("/eat");
	sem_unlink("/time");
	sem_unlink("/meal");
	sem_unlink("/dead");
	sem_unlink("/lock");
	sem_unlink("/clock");
	d->forks = sem_open("/forks", O_CREAT, 0644, d->tab[0]);
	d->eat = sem_open("/eat", O_CREAT, 0644, 1);
	d->time = sem_open("/time", O_CREAT, 0644, 1);
	d->meal = sem_open("/meal", O_CREAT, 0644, 1);
	d->dead = sem_open("/dead", O_CREAT, 0644, 1);
	d->lock = sem_open("/lock", O_CREAT, 0644, 1);
	d->clock = sem_open("/clock", O_CREAT, 0644, 1);
	d->start = 0;
	d->is_dead = 0;
	d->start_time = ft_time();
	return (1);
}

static int	ft_init_philo(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->tab[0])
	{
		d->philo.id = i + 1;
		d->philo.data = d;
		d->philo.eat_count = 0;
		d->philo.pid = fork();
		if (d->philo.pid == -1)
			return (write(2, "error creating process\n", 24), kill(d->philo.pid, 13), 0);//free all
		d->philo.last_meal = d->start_time;
		if (d->philo.pid == 0)
			ft_action(&d->philo);
	}
	waitpid(-1, 0, 0);
	return (1);
}

int	ft_philo(t_data *d)
{
	if (!ft_init_fork(d))
		return (0);
	if (!ft_init_philo(d))
		return (0);
	ft_free_data(d);
	sem_close(d->lock);
	sem_close(d->clock);
	sem_close(d->eat);
	sem_close(d->dead);
	sem_close(d->meal);
	return (1);
}
