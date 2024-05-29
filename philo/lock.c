/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:07:27 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 18:55:22 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_start(t_data *d)
{
	if (pthread_mutex_lock(&d->check))
		return (0);
	d->start = 1;
	if (pthread_mutex_unlock(&d->check))
		return (0);
	return (1);
}

int	ft_get_start(t_data *d)
{
	int	start;

	if (pthread_mutex_lock(&d->check))
		return (0);
	start = d->start;
	if (pthread_mutex_unlock(&d->check))
		return (0);
	return (1);
}

int	ft_set_meal(t_philo *p)
{
	if (pthread_mutex_lock(&p->data->check))
		return (0);
	p->last_meal = ft_time();
	if (pthread_mutex_unlock(&p->data->check))
		return (0);
	return (1);
}

long	ft_get_meal(t_philo *p)
{
	long	meal;

	if (pthread_mutex_lock(&p->data->check))
		return (0);
	meal = p->last_meal;
	if (pthread_mutex_unlock(&p->data->check))
		return (0);
	return (meal);
}

int	ft_dead(t_data *data)
{
	int	dead;

	if (pthread_mutex_lock(&data->dead))
		return (0);
	dead = data->is_dead;
	if (pthread_mutex_unlock(&data->dead))
		return (0);
	return (dead);
}
