/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:38:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:37:32 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->tab[0])
		if (pthread_mutex_init(&d->philo[i].fork_l, NULL))
			return (write(2, "mutex_init failed\n", 19), 0);
	i = -1;
	while (++i < d->tab[0])
		d->philo[i].fork_r = &d->philo[(i + 1) % (d->tab[0])].fork_l;
	if (pthread_mutex_init(&d->lock, NULL))
		return (0);
	if (pthread_mutex_init(&d->check, NULL))
		return (0);
	if (pthread_mutex_init(&d->dead, NULL))
		return (0);
	if (pthread_mutex_init(&d->count, NULL))
		return (0);
	return (1);
}
