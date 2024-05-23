/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/23 19:55:49 by cmasnaou         ###   ########.fr       */
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
# include <sys/time.h>

struct s_data;

typedef struct s_philo
{
    int				id;
    pid_t		    philo;//pid
    long			last_meal;
    int		        eat_count;
    struct s_data	*data;
}   t_philo;

typedef struct s_data
{
    long	tab[5];
    sem_t   *forks;//
    long	start_time;
    int		is_dead;
    int     start;
    sem_t *lock;//
    sem_t *clock;//
    t_philo	*philo;
}   t_data;


int 	ft_print(t_philo *p, char *s);
int     ft_sleep(t_philo * p, long t);
void	ft_free_data(t_data *d);
void    ft_action(t_data *d, int i);
void    *ft_check(void *d0);
long	ft_time();
int     ft_eat(t_philo *p);
int		ft_fork(t_data *d);
int		ft_philo(t_data *d);
int     one_philo(t_data *d);

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
