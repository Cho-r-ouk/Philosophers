/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/05/12 15:20:52 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The threads of a computer program allow the program to execute sequential actions or many actions at once.
// The typical difference is that threads (of the same process) run in a shared memory space, while processes run in separate memory spaces.
/* 
Process:
- Can have multiple threads
- When using fork(), duplicates everything
- This means a variable is just copied, if we modify the variable in one process it won't be modified in the other one

Threads:
- share memory space
- if I declare a variable somewhere, and modify it inside of a thread, it will be changed for every other threads as well
- can run in what's called a "memory race"
- since the memory is shared between threads, if multiple threads try to access the same variable at the same time, it's called a "memory race" since the "fastest" thread will modify the variable value, and then the other one will. But the value of the first modification could have useful somewhere.
- we have to protect our program against "memory race", like we do for "memory leaks"
*/
// A mutex is basically a lock. We can lock a variable so that only one thread can access the variable at a time. 
// When the first thread finished its operation on the variable, we unlock the mutex so that the other thread can access the variable.

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

struct s_data;

typedef struct s_philo
{
    int				id;
    pthread_t		philo;
    pthread_mutex_t	fork_l;
    pthread_mutex_t	*fork_r;
    long			last_meal;
    long	        start_time;
    // int             is_eating;
    struct s_data	*data;
}   t_philo;

typedef struct s_data
{
    long	tab[5];
    int		eat_count;
    int		is_dead;
    int     start;//
    pthread_mutex_t data_lock;
    pthread_mutex_t print_lock;
    pthread_mutex_t dead_lock;
    pthread_mutex_t sleep_lock;
    pthread_mutex_t time_lock;
    t_philo	*philo;
}   t_data;


int		word_count(char const *s, char c);
char	**ft_free(char **p, int i);
char	**ft_split(char const *s, char c);
int		arg_count(int ac, char **av);
int		is_valid(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		parse(int ac, char **av, t_data *d);
int		ft_atoi(char *s);
long	get_time();
int 	set_message(t_philo *p, char *s);
void	free_data(t_data *d);
int     set_usleep(t_philo * p, long t);
void	*set_action(void *p0);
int		set_fork(t_data *d);
int		set_philo(t_data *d);
int     dead_check(t_philo *p);

#endif
