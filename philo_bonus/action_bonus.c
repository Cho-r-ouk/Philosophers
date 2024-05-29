/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 20:16:00 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_actions(t_philo *p)
{
	if (sem_wait(p->data->forks) == -1)
		return (0);
	if (ft_print(p, "has taken a fork"))
		return (0);
	if (sem_wait(p->data->forks) == -1)
		return (0);
	if (ft_print(p, "has taken a fork"))
		return (0);
	if (!ft_eat(p))
		return (0);
	if (sem_post(p->data->forks) == -1)
		return (0);
	if (sem_post(p->data->forks) == -1)
		return (0);
	if (ft_print(p, "is sleeping"))
		return (0);
	if (ft_sleep(p, p->data->tab[3]))
		return (0);
	if (ft_print(p, "is thinking"))
		return (0);
	return (1);
}

int	ft_action(t_philo *p)
{
	int	j;

	if (pthread_create(&p->data->check, NULL, &ft_check, p))
		return (0);
	if (pthread_detach(p->data->check))
		return (0);
	if (!(p->id % 2))
	{
		if (ft_print(p, "is thinking"))
			return (0);
		if (ft_sleep(p, p->data->tab[2] / 2))
			return (0);
	}
	while (!p->data->is_dead)
		if (!ft_actions(p))
			return (0);
	return (1);
}
