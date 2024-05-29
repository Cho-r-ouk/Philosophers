/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:27:26 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_actions(t_philo	*p)
{
	if (pthread_mutex_lock(&p->fork_l))
		return (0);
	if (ft_print(p, "has taken a fork"))
		return (0);
	if (pthread_mutex_lock(p->fork_r))
		return (0);
	if (ft_print(p, "has taken a fork"))
		return (0);
	if (!ft_eat(p))
		return (0);
	if (ft_print(p, "is sleeping"))
		return (0);
	if (ft_sleep(p, p->data->tab[3]))
		return (0);
	if (ft_print(p, "is thinking"))
		return (0);
	return (1);
}

void	*ft_action(void *p0)
{
	t_philo	*p;

	p = (t_philo *)p0;
	while (!ft_get_start(p->data))
		usleep(1);
	if (!(p->id % 2))
		ft_sleep(p, p->data->tab[2] / 2);
	while (!ft_dead(p->data))
		if (!ft_actions(p))
			break ;
	return (ft_free_data(p->data), NULL);
}
