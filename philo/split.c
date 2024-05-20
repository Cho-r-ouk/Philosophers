/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/17 21:32:27 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (++count);
}

static int	word_lenth(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_free(char **p, int i)
{
	int	j;

	j = -1;
	while (++j < i)
		free(p[j]);
	free(p);
	return (NULL);
}

static char	**ft_conditions(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	if (*s == '\0' || word_count(s, c) == 0)
		p = (char **)malloc(sizeof (char *));
	else
		p = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		k;
	int		i;

	k = 0;
	i = 0;
	p = ft_conditions(s, c);
	if (p == NULL)
		return (NULL);
	while (s[i] && k < word_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			p[k] = (char *)malloc((1 + word_lenth(s, c, i)) * sizeof(char));
			if (!p[k])
				return (ft_free(p, k));
			ft_strlcpy(p[k++], s + i, word_lenth(s, c, i) + 1);
			i += word_lenth(s, c, i);
		}
	}
	p[k] = NULL;
	return (p);
}
