/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/22 12:14:16 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long ft_time()
{
    struct timeval t;

    if (gettimeofday(&t, NULL))
        return (write(2, "error getting time\n", 20), 0);
    return (t.tv_sec * 1000 + t.tv_usec / 1000);    
}

int ft_sleep(t_philo * p, long t)
{
    long time;

    time = ft_time() + t;
    while (ft_time() < time)
    {
        if (p && p->data->is_dead)
            return (ft_print(p, "is dead"));
        usleep(100);
    }
    return (0);
}

void ft_free_data(t_data *d)
{
	int i = 0;
	while (i < d->tab[0])
    {
        // sem_post(d->forks);
        sem_close(d->forks);
        sem_unlink("/sem");
        sem_unlink("lock");
        sem_unlink("clock");
        // pthread_mutex_unlock(&d->philo[i].fork_l);
		// pthread_mutex_destroy(&d->philo[i].fork_l);
        i++;
    }
} 
