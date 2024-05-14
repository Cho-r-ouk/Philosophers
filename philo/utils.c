/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/14 10:15:05 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_data(t_data *d)
{
	int i = 0;
	while (i < d->tab[0])
    {
        pthread_mutex_unlock(&d->philo[i].fork_l);
		pthread_mutex_destroy(&d->philo[i].fork_l);
        i++;
    }
} 


long get_time()
{
    struct timeval t;

    if (gettimeofday(&t, NULL))
        return (write(2, "error getting time\n", 20), 0);
    return (t.tv_sec * 1000 + t.tv_usec / 1000);    
}

int time_check(t_philo *p)
{
    int status;
    int i = 0;

    while (i < p->data->tab[0])
    {
        pthread_mutex_lock(&p->data->time_lock);
        status = (get_time() - p->data->philo[i].last_meal > p->data->tab[1]);
        if (status)
        {
            // printf("%d time_check: %d\n", p->data->philo[i].id, status);
            // printf("%d last meal: %ld\n", p->data->philo[i].id, get_time() - p->data->philo[i].last_meal);
            p->data->is_dead = p->data->philo[i].id;
            pthread_mutex_unlock(&p->data->time_lock);
            return (status);
        }
        pthread_mutex_unlock(&p->data->time_lock);
        i++;
    }
    return (status);
}

int set_usleep(t_philo * p, long t)
{
    long time;

    time = get_time();
    while (get_time() < time + t)
    {
        if (p->data->is_dead)
            return (1);
        if (time_check(p))
            return (p->data->is_dead = p->id, 1);
        usleep(100);
    }
    return (0);
}

int set_message(t_philo *p, char *s)
{
    t_philo philo;
    static int i = 0;
    long time;

    philo = p->data->philo[dead_check(p) - 1];
    pthread_mutex_lock(&p->data->print_lock);
    time = get_time() - p->start_time;
    if (i)
        return (pthread_mutex_unlock(&p->data->print_lock), 1);
    if (p->data->tab[4] && p->data->eat_count >= p->data->tab[0] * p->data->tab[4])
    {
        i++;
        pthread_mutex_unlock(&p->data->print_lock);
        return (1);
    }
    if (!dead_check(p) && time_check(p))
    {
        (p->data->is_dead = p->id, i++);
        printf("%-6ld  %-3d  died\n", time, p->data->is_dead);
        pthread_mutex_unlock(&p->data->print_lock);
        return (1);
    }
    if (dead_check(p))
    {
        i++;
        printf("%-6ld  %-3d  died\n", time, p->data->is_dead);
        pthread_mutex_unlock(&p->data->print_lock);
        return (1);
    }
    if (!dead_check(p))
        printf("%-6ld  %-3d  %s\n", time, p->id, s);
    pthread_mutex_unlock(&p->data->print_lock);
    return (0);
}
