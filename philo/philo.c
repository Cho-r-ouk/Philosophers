/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/19 16:29:55 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_init(t_data *d)
{
    int i;

    d->start_time = ft_time();
    d->is_dead = 0;
    d->start = 0;
    i = -1;
    while (++i < d->tab[0])
    {
        d->philo[i].id = i + 1;
        d->philo[i].data = d;
        d->philo[i].eat_count = 0;
        d->philo[i].last_meal = d->start_time; 
    }
}

int ft_philo(t_data *d)
{
    int i;
    pthread_t check;

    if (!ft_fork(d))
        return (0);
    pthread_mutex_init(&d->clock, NULL);
    pthread_mutex_init(&d->lock, NULL);
    i = -1;
    ft_init(d);
    while (++i < d->tab[0]) 
        if (pthread_create(&d->philo[i].philo, NULL, &ft_action, (void *)&d->philo[i]))
            return (write(2, "error creating thread\n", 23), 0);
    (d->start = 1, i = -1);
    if (pthread_create(&check, NULL, &ft_check, d))
        return (write(2, "error creating thread\n", 23), 0);
    if (pthread_join(check, NULL))
        return (write(2, "error joining thread\n", 22), 0);
    while (++i < d->tab[0])
        if (pthread_join(d->philo[i].philo, NULL))
            return (write(2, "error joining thread\n", 22), 0);
    ft_free_data(d);
    pthread_mutex_destroy(&d->lock);
    pthread_mutex_destroy(&d->clock);
    free(d->philo);
    return (1);
}
