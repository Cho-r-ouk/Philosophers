/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/23 19:59:13 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_action(t_data *d, int i)
{
    sem_wait(d->forks);
    ft_print(&d->philo[i], "has taken a fork");
    sem_wait(d->forks);
    ft_print(&d->philo[i], "has taken a fork");
    ft_eat(&d->philo[i]);
    sem_post(d->forks);
    sem_post(d->forks);
    ft_print(&d->philo[i], "is sleeping");
    ft_sleep(&d->philo[i], d->tab[3]);
    ft_print(&d->philo[i], "is thinking");
    // exit (0);   //if dead
    exit(0);
    return ;
}
