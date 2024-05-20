/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:40:55 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/17 21:58:41 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_action(void *p0)
{
    t_philo *p;
    
    p = (t_philo *)p0;
    while (!p->data->start)
        ;
    if (!(p->id % 2))
        ft_sleep(p, p->data->tab[2] / 2);
    while (!p->data->is_dead)
    {
        pthread_mutex_lock(&p->fork_l);
        if(ft_print(p, "has taken a fork"))
            break ;
        pthread_mutex_lock(p->fork_r);
        if (ft_print(p, "has taken a fork"))
            break ;
        if (!ft_eat(p))
            break ;
        if (ft_print(p, "is sleeping"))
            break ;
        if(ft_sleep(p, p->data->tab[3]))
            break ;
        if (ft_print(p, "is thinking"))
            break ;
    }
    return (ft_free_data(p->data), NULL);
}
