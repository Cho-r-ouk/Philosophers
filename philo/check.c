/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:13:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:30:20 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check(void *d0)
{
	t_data	*d;
	int		i;

	d = (t_data *)d0;
	while (!ft_dead(d))
	{
		i = -1;
		while ((++i < d->tab[0]) && !ft_dead(d))
		{
			if (ft_time() - ft_get_meal(&d->philo[i]) > d->tab[1])
			{
				if (pthread_mutex_lock(&d->dead))
					return (NULL);
				d->is_dead = d->philo[i].id;
				if (pthread_mutex_unlock(&d->dead))
					return (NULL);
				return (NULL);
			}
		}
	}
	return (NULL);
}
