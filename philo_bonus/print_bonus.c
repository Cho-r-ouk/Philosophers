/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:04:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/23 19:56:47 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void ft_putnbr(int n)
{
    if (n >= 0 && n <= 9)
    {
        n += '0';
        write(1, &n, 1);
        return ;
    }
    ft_putnbr(n / 10);
    ft_putnbr(n % 10);
}

int ft_print(t_philo *p, char *s)
{
    static int i = 0;

    // pthread_mutex_lock(&p->data->lock);
    sem_wait(p->data->lock);
    if (i)
        return (sem_post(p->data->lock), 1);
    if (p->data->tab[4] && p->eat_count > p->data->tab[4])
        return (++i, sem_post(p->data->lock), 1);
    if (p->data->is_dead)
    {
        printf("%-6ld\t%-3d\tdied\n", ft_time() - p->data->start_time, p->data->is_dead);
        // while (waitpid(p->philo, NULL, 0) != -1)
            // exit(0);
        return (++i, sem_post(p->data->lock), 1);
    }
    if (!p->data->is_dead)
    {
        ft_putnbr(ft_time() - p->data->start_time);
        write(1, "\t", 1);
        ft_putnbr(p->id);
        write(1, "\t", 1);
        write(1, s, ft_strlen(s));
        write(1, "\n", 1);
        // printf("%-6ld\t%-3d\t%s\n", ft_time() - p->start_time, p->id, s);
    }
    return (sem_post(p->data->lock), 0);
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

