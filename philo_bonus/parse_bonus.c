/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:48 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/28 12:48:35 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_valid(char *s)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(s))
		return (0);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (ft_strlen(s) == i)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && s[i + 1] == '0')
			return (1);
		if (!(s[i] >= '0' && s[i] <= '9')
			&& s[i] != ' ' && s[i] != '+')
			return (0);
		if ((s[i] >= '0' && s[i] <= '9')
			&& s[i + 1] == '+')
			return (0);
		if (s[i] == '+' && (!s[i + 1] || s[i + 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	arg_count(int ac, char **av)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (-1);
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			k++;
			j++;
		}
		ft_free(split, j);
		i++;
	}
	return (k);
}

int	parse(int ac, char **av, t_data *d)
{
	char	**split;

	d->i[2] = arg_count(ac, av);
	if (d->i[2] < 4 || d->i[2] > 5)
		return (write (2, "Error\n", 6), 1);
	(1) && (d->i[0] = 0, d->i[3] = -1, d->tab[4] = 0);
	while (++d->i[0] < ac)
	{
		(1) && (split = ft_split(av[d->i[0]], ' '), d->i[1] = -1);
		if (!split)
			return (write (2, "Error\n", 6), 1);
		while (split[++d->i[1]])
		{
			d->i[4] = word_count(av[d->i[0]], ' ');
			d->tab[++d->i[3]] = ft_atoi(split[d->i[1]]);
			if (d->tab[0] == 0)
				return (ft_free(split, d->i[4]), 0);
			if (d->i[3] == 4 && d->tab[d->i[3]] == 0)
				return (ft_free(split, d->i[4]), 1);
			if (d->tab[d->i[3]] == 0)
				return (write (2, "Error\n", 6), ft_free(split, d->i[4]), 1);
		}
		ft_free(split, d->i[1]);
	}
	return (0);
}
