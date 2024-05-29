/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:37:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 20:09:46 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	d;

	d = (t_data){0};
	if (parse(ac, av, &d))
		return (1);
	if (one_philo(&d))
		return (0);
	if (!ft_philo(&d))
		return (1);
	return (0);
}
