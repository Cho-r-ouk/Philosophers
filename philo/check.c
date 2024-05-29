/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:13:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:18:23 by cmasnaou         ###   ########.fr       */
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
				pthread_mutex_lock(&d->dead);
				d->is_dead = d->philo[i].id;
				pthread_mutex_unlock(&d->dead);
				return (NULL);
			}
		}
	}
	return (NULL);
}
