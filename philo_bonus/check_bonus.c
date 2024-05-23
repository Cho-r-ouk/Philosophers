/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:13:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/22 13:55:18 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void *ft_check(void *d0)
{
    t_data *d;
    int i;

    d = (t_data *)d0;
    while (!d->is_dead)
    {
        i = -1;
        while ((++i < d->tab[0]) && !d->is_dead)
        {
            if (ft_time() - d->philo[i].last_meal > d->tab[1])
            {
                // pthread_mutex_lock(&d->clock);
                sem_wait(d->clock);
                d->is_dead = d->philo[i].id;
                // pthread_mutex_unlock(&d->clock);
                sem_post(d->clock);
                return (NULL);
            }
        }
    }
    return (NULL);

}
