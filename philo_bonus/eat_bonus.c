/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:46 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 20:09:25 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_eat(t_philo *p)
{
	if (sem_wait(p->data->eat) == -1)
		return (0);
	p->eat_count += 1;
	if (sem_post(p->data->eat) == -1)
		return (0);
	p->last_meal = ft_time();
	if (ft_print(p, "is eating"))
		return (0);
	if (ft_sleep(p, p->data->tab[2]))
		return (0);
	return (1);
}
