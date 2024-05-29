/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:46 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:18:49 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_count(t_philo *p)
{
	int	count;

	if (pthread_mutex_lock(&p->data->count))
		return (0);
	count = p->eat_count;
	if (pthread_mutex_unlock(&p->data->count))
		return (0);
	return (count);
}

int	ft_set_count(t_philo *p)
{
	if (pthread_mutex_lock(&p->data->count))
		return (0);
	p->eat_count += 1;
	if (pthread_mutex_unlock(&p->data->count))
		return (0);
	return (1);
}

int	ft_eat(t_philo *p)
{
	if (!ft_set_count(p))
		return (0);
	if (!ft_set_meal(p))
		return (0);
	if (ft_print(p, "is eating"))
		return (0);
	if (ft_sleep(p, p->data->tab[2]))
		return (0);
	if (pthread_mutex_unlock(&p->fork_l))
		return (0);
	if (pthread_mutex_unlock(p->fork_r))
		return (0);
	return (1);
}
