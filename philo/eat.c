/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:12:46 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/19 16:21:00 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_eat(t_philo *p)
{
    p->eat_count += 1;
    p->last_meal = ft_time();
    if (ft_print(p, "is eating"))
        return (0);
    if (ft_sleep(p, p->data->tab[2]))
        return (0);
    pthread_mutex_unlock(&p->fork_l);
    pthread_mutex_unlock(p->fork_r);
    return (1);
}
