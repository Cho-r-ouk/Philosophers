/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/29 19:43:01 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	pid_t			pid;
	long			last_meal;
	int				eat_count;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long		tab[5];
	long		start_time;
	int			is_dead;
	int			start;
	int			i[5];
	sem_t		*forks;
	sem_t		*lock;
	sem_t		*clock;
	sem_t		*eat;
	sem_t		*time;
	sem_t		*meal;
	sem_t		*dead;
	pthread_t	check;
	t_philo		philo;
}	t_data;

int		parse(int ac, char **av, t_data *d);
size_t	ft_strlcpy(char *d, const char *s, size_t n);
size_t	ft_strlen(const char *s);
int		word_count(char const *s, char c);
int		arg_count(int ac, char **av);
char	**ft_free(char **p, int i);
char	**ft_split(char const *s, char c);
long	ft_time(void);
int		is_valid(char *s);
int		ft_atoi(char *s);
int		one_philo(t_data *d);
int		ft_print(t_philo *p, char *s);
int		ft_eat(t_philo *p);
int		ft_philo(t_data *d);
int		ft_sleep(t_philo *p, long t);
void	ft_close(t_data *d);
void	ft_unlink(void);
int		ft_action(t_philo *p);
void	*ft_check(void *d0);

#endif
