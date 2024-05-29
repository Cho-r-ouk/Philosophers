/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 15:08:11 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_action(t_philo *p)
{
	int	j;

	if (pthread_create(&p->data->check, NULL, &ft_check, p))
		return ;
	if (pthread_detach(p->data->check))
		return ;
	if (!(p->id % 2))
	{
		ft_print(p, "is thinking");
		ft_sleep(p, p->data->tab[2] / 2);
	}
	while (!p->data->is_dead)
	{
		sem_wait(p->data->forks);
		ft_print(p, "has taken a fork");
		sem_wait(p->data->forks);
		ft_print(p, "has taken a fork");
		ft_eat(p);
		sem_post(p->data->forks);
		sem_post(p->data->forks);
		ft_print(p, "is sleeping");
		ft_sleep(p, p->data->tab[3]);
		ft_print(p, "is thinking");
	}
	return ;
}
