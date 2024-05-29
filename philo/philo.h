/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 16:19:45 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	long			last_meal;
	int				eat_count;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	*fork_r;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long			tab[5];
	long			start_time;
	int				is_dead;
	int				start;
	int				i[5];
	t_philo			*philo;
	pthread_mutex_t	lock;
	pthread_mutex_t	check;
	pthread_mutex_t	dead;
	pthread_mutex_t	count;
}	t_data;

int		ft_print(t_philo *p, char *s);
int		ft_sleep(t_philo *p, long t);
void	*ft_action(void *p0);
void	*ft_check(void *d0);
void	ft_free_data(t_data *d);
int		ft_set_start(t_data *d);
int		ft_get_start(t_data *d);
int		ft_set_meal(t_philo *p);
long	ft_get_meal(t_philo *p);
int		ft_set_count(t_philo *p);
int		ft_get_count(t_philo *p);
int		ft_dead(t_data *data);
int		ft_destroy(t_data *d);
long	ft_time(void);
int		ft_eat(t_philo *p);
int		ft_fork(t_data *d);
int		ft_philo(t_data *d);
int		one_philo(t_data *d);
int		word_count(char const *s, char c);
char	**ft_free(char **p, int i);
char	**ft_split(char const *s, char c);
int		arg_count(int ac, char **av);
int		is_valid(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		parse(int ac, char **av, t_data *d);
int		ft_atoi(char *s);

#endif
