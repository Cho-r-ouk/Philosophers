/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/12 14:39:10 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int set_philo(t_data *d)
{
    int i;

    pthread_mutex_init(&d->data_lock, NULL);
    pthread_mutex_init(&d->print_lock, NULL);
    pthread_mutex_init(&d->dead_lock, NULL);
    pthread_mutex_init(&d->sleep_lock, NULL);
    pthread_mutex_init(&d->time_lock, NULL);
    if (!set_fork(d))
        return (free_data(d), 0);
    d->eat_count = 0;
    d->is_dead = 0;
    d->start = 0;
    i = -1;
    while (++i < d->tab[0])
    {
        d->philo[i].id = i + 1;
        d->philo[i].data = d;
    }
    i = -1;
    while (++i < d->tab[0])
        if (pthread_create(&d->philo[i].philo, NULL, &set_action, (void *)&d->philo[i]))
            return (write(2, "error creating thread\n", 23), 0);
    i = -1;
    while (++i < d->tab[0])
    {
        d->philo[i].start_time = get_time();
        d->philo[i].last_meal = d->philo[i].start_time;
    }
    d->start = 1;
    i = -1;
    while (++i < d->tab[0])
        if (pthread_join(d->philo[i].philo, NULL))
            return (write(2, "error joining thread\n", 22), 0);
    free_data(d);
    pthread_mutex_destroy(&d->data_lock);
    pthread_mutex_destroy(&d->print_lock);
    pthread_mutex_destroy(&d->dead_lock);
    pthread_mutex_destroy(&d->sleep_lock);
    pthread_mutex_destroy(&d->time_lock);
    free(d->philo);
    return (1);
}
