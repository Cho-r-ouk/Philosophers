/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:04:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/17 22:04:37 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_print(t_philo *p, char *s)
{
    static int i = 0;

    pthread_mutex_lock(&p->data->lock);
    if (i)
        return (pthread_mutex_unlock(&p->data->lock), 1);
    if (p->data->tab[4] && p->eat_count > p->data->tab[4])
        return (++i, pthread_mutex_unlock(&p->data->lock), 1);
    if (p->data->is_dead)
    {
        printf("%-6ld\t%-3d\tdied\n", ft_time() - p->data->start_time, p->data->is_dead);
        return (++i, pthread_mutex_unlock(&p->data->lock), 1);
    }
    if (!p->data->is_dead)
        printf("%-6ld\t%-3d\t%s\n", ft_time() - p->data->start_time, p->id, s);
    return (pthread_mutex_unlock(&p->data->lock), 0);
}

int one_philo(t_data *d)
{
    if (d->tab[0] == 1)
    {
        printf("0\t1\thas taken a fork\n");
        ft_sleep(NULL, d->tab[1]);
        printf("%-6ld\t%-3d\tdied\n", d->tab[1], 1);
        return (1);
    }
    return (0);
}

