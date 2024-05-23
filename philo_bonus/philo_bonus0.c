/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/20 15:56:05 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
    int pid;
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
    i = -1;
    ft_init(d);
    while (++i < d->tab[0])
    {
        // d->philo[i].philo = fork();
        pid = fork();
        printf("philo\n");
        // if (d->philo[i].philo == -1)
        if (pid == -1)
            return (write(2, "error creating process\n", 24), 0);
        // if (pthread_create(&d->philo[i].philo, NULL, &ft_action, (void *)&d->philo[i]))
        //     return (write(2, "error creating thread\n", 23), 0);
        if (pid == 0)
        {
            sem_wait(d->forks);
            printf("%d\thas taken a fork\n", i);
            // exit (0);   
        }
        else
            waitpid(pid, NULL, 0);
    }
    (d->start = 1, i = -1);
    // if (pthread_create(&check, NULL, &ft_check, d))
    //     return (write(2, "error creating thread\n", 23), 0);
    // if (pthread_join(check, NULL))
    //     return (write(2, "error joining thread\n", 22), 0);
    // while (++i < d->tab[0])
    // {
        // if (pthread_join(d->philo[i].philo, NULL))
        //     return (write(2, "error joining thread\n", 22), 0);
    // }
    ft_free_data(d);
    
    /******************************/
    // sem_unlink("lock");
    // sem_unlink("clock");
    sem_close(d->lock);
    sem_close(d->clock);
    // pthread_mutex_destroy(&d->lock);
    // pthread_mutex_destroy(&d->clock);
    /******************************/
    // free(d->philo);
    // free(d);
    return (1);
}
