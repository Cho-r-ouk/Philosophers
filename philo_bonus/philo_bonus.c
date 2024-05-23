/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/23 20:27:40 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int ft_init(t_philo *p)
{
    p->eat_count = 0;
    p->philo = fork();
    p->last_meal = p->data->start_time; 
    if (p->philo == -1)
        return (write(2, "error creating process\n", 24), 0);
    return (1);
}

int ft_philo(t_data *d)
{
    int i;
    pid_t pid;
    pthread_t check;

    // d = (t_data *)malloc(sizeof(t_data));
    if (!ft_fork(d))
        return (0);
    /******************************/
    sem_unlink("lock");
    sem_unlink("clock");
    d->lock = sem_open("/lock", O_CREAT, 0644, 1);
    d->clock = sem_open("/clock", O_CREAT, 0644, 1);
    // pthread_mutex_init(&d->clock, NULL);
    // pthread_mutex_init(&d->lock, NULL);
    /******************************/
  
    if (pthread_create(&check, NULL, &ft_check, d))
        return (write(2, "error creating thread\n", 23), 0);
    if (pthread_join(check, NULL))
        return (write(2, "error joining thread\n", 22), 0);
  
    d->is_dead = 0;
    d->start = 0;
    i = -1;
    // pid = fork();
    // if (pid == -1)
    //     return (write(2, "error creating process\n", 24), 0);
    // if (pid == 0)
    // {
        i = -1;
        while (++i < d->tab[0])
        {
            d->philo[i].id = i + 1;
            d->philo[i].data = d;
            if (!ft_init(&d->philo[i]))
                return (0);        
            if (i == 0)
                d->start_time = ft_time();
            if (d->philo[i].philo == 0)
            {
                // if ((d->philo[i].philo % 2) == 0)
                //     sleep(1);
                while (1)
                    ft_action(d, i);
            }
        }
    // }
    // else
     i = -1;
    while (++i < d->tab[0])
        waitpid(d->philo[i].philo, NULL, 0);
        // wait(NULL);
    ft_free_data(d);
    sem_close(d->lock);
    sem_close(d->clock);
    return (1);
}
