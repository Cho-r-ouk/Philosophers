/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:13:36 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 15:10:32 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check(void *p0)
{
	static int	count;
	t_philo		*p;
	int			i;

	p = (t_philo *)p0;
	while (!p->data->is_dead)
	{
		i = -1;
		while (++i < p->data->tab[0])
		{
			if (p->data->tab[4] && p->eat_count > p->data->tab[4] && count++)
				(count >= p->data->tab[0])
					&& (ft_free_data(p->data), kill(p->pid, 13));
			if (ft_time() - p->last_meal > p->data->tab[1])
			{
				p->data->is_dead = p->id;
				sem_wait(p->data->clock);
				ft_print(p, "died");
				(ft_free_data(p->data), kill(p->pid, 13));
				return (sem_post(p->data->clock), NULL);
			}
		}
	}
	return (NULL);
}
