/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:48 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/04/24 14:21:57 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//fix -0 and malloc = NULL sigfault

#include "philo.h"

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

int parse(int ac, char **av, t_data *d)
{
	int		i;
    int     j;
    int     k;
	char	**split;
    
	k = arg_count(ac, av);
    if (k < 4 || k > 5)
        return (write (2, "Error\n", 6), 1);
	(i = 0, k = -1, d->tab[4] = 0);
	while (++i < ac)
	{
		(split = ft_split(av[i], ' '), j = -1);
		if (!split)
			return (write (2, "Error\n", 6), 1);
		while (split[++j])
		{
			d->tab[++k] = ft_atoi(split[j]);
			if (d->tab[0] == 0)
				return (0);
			if (d->tab[k] == 0)
				return (write (2, "Error\n", 6), ft_free(split, word_count(av[i], ' ')), 1);
		}
		ft_free(split, j);
	}
	return (0);
}
