/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:04:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 20:15:46 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_print(t_philo *p, char *s)
{
	static int	i = 0;

	if (sem_wait(p->data->lock) == -1)
		return (1);
	if (i)
		return (sem_post(p->data->lock), 1);
	if (p->data->tab[4] && p->eat_count > p->data->tab[4])
		return (++i, sem_post(p->data->lock), 1);
	if (p->data->is_dead)
	{
		printf("%-6ld\t%-3d\tdied\n",
			ft_time() - p->data->start_time, p->data->is_dead);
		kill(p->pid, 13);
		return (++i, sem_post(p->data->lock), 1);
	}
	if (!p->data->is_dead)
		printf("%-6ld\t%-3d\t%s\n", ft_time() - p->data->start_time, p->id, s);
	return ((sem_post(p->data->lock) == -1));
}

int	one_philo(t_data *d)
{
	long	time;

	if (d->tab[0] == 0)
		return (1);
	time = ft_time() + d->tab[1];
	if (d->tab[0] == 1)
	{
		printf("0\t1\thas taken a fork\n");
		while (ft_time() < time)
			usleep(10);
		printf("%-6ld\t%-3d\tdied\n", d->tab[1], 1);
		return (1);
	}
	return (0);
}
