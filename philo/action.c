/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/12 15:21:32 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int dead_check(t_philo *p)
{
    int status;
    
    pthread_mutex_lock(&p->data->dead_lock);
    status = p->data->is_dead;
    pthread_mutex_unlock(&p->data->dead_lock);
    return (status);
}

int get_start(t_philo *p)
{
    int status;
    
    pthread_mutex_lock(&p->data->time_lock);
    status = p->data->start;
    pthread_mutex_unlock(&p->data->time_lock);
    return (status);
}

int is_eating(t_philo *p)
{
    pthread_mutex_lock(&p->fork_l);
    if(set_message(p, "has taken a fork"))
        return (0);
    pthread_mutex_lock(p->fork_r);
    if (set_message(p, "has taken a fork"))
        return (0);
    pthread_mutex_lock(&p->data->data_lock);
    (p->data->eat_count)++;
    p->last_meal = get_time();
    pthread_mutex_unlock(&p->data->data_lock);
    if (set_message(p, "is eating"))
        return (0);
    if (!dead_check(p))
    {
        if(set_usleep(p, p->data->tab[2]))
            return (0);
    }
    else
        return (0);
    pthread_mutex_unlock(&p->fork_l);
    pthread_mutex_unlock(p->fork_r);
    return (1);
}

void *set_action(void *p0)
{
    t_philo *p;
    
    p = (t_philo *)p0;
    while (!get_start(p))
        ;
    if (!(p->id % 2))
        set_usleep(p, 10);
    while (1)
    {
        if (!is_eating(p))
            break ;
        if (set_message(p, "is sleeping"))
            break ;
        if (dead_check(p))
            break ;
        if(set_usleep(p, p->data->tab[3]))
            break ;
        if (set_message(p, "is thinking"))
            break ;
        if (dead_check(p))
            break ;
    }
    return (free_data(p->data), NULL);
}
