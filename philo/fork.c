/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:38:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:18:56 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_fork(t_data *d)
{
	int	i;

	d->philo = (t_philo *)malloc(sizeof(t_philo) * (d->tab[0]));
	if (!d->philo)
		return (write(2, "malloc failed\n", 15), 0);
	i = 0;
	while (i < d->tab[0])
	{
		if (pthread_mutex_init(&d->philo[i].fork_l, NULL))
			return (write(2, "mutex_init failed\n", 19), 0);
		i++;
	}
	i = 0;
	while (i < d->tab[0])
	{
		d->philo[i].fork_r = &d->philo[(i + 1) % (d->tab[0])].fork_l;
		i++;
	}
	return (1);
}
