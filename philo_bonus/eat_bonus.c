/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:46 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/27 18:36:08 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_eat(t_philo *p)
{
	sem_wait(p->data->eat);
	p->eat_count += 1;
	sem_post(p->data->eat);
	p->last_meal = ft_time();
	if (ft_print(p, "is eating"))
		return (0);
	if (ft_sleep(p, p->data->tab[2]))
		return (0);
	return (1);
}
