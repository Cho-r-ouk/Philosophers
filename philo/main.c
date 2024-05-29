/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:37:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 19:33:49 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	d;

	d = (t_data){0};
	if (parse(ac, av, &d))
		return (1);
	if (one_philo(&d))
		return (0);
	if (!ft_malloc(&d))
		return (1);
	ft_philo(&d);
	ft_free_data(&d);
	ft_destroy(&d);
	free(d.philo);
	return (0);
}
