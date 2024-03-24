/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 18:29:35 by cmasnaou         ###   ########.fr       */
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

struct s_data;

typedef struct s_philo
{
    int id;
    pthread_t philo;
    pthread_mutex_t  fork_l;
    pthread_mutex_t  *fork_r;
    int  is_eating;
    int  eat_count;
    // int  is_dead;
    int last_meal;
    struct s_data  *data;
}   t_philo;

typedef struct s_data
{
    int tab[5];
    // int start;
    int start_time;
    int  is_dead;
    // pthread_t *philo;
    // int full;
    t_philo *philo;
    // pthread_mutex_t *fork;
    // pthread_mutex_t lock;
    // pthread_mutex_t end;
}   t_data;

// tab[0]   :   number_of_philosophers (and also the number of forks)
// tab[1]   :   time_to_die (in milliseconds) (from beginning of their last meal)
// tab[2]   :   time_to_eat (in milliseconds) (the time they will hold two forks)
// tab[3]   :   time_to_sleep (in milliseconds)
// tab[4]   :   [number_of_times_each_philosopher_must_eat]


int	word_count(char const *s, char c);
char	**ft_free(char **p, int i);
char	**ft_split(char const *s, char c);
int	arg_count(int ac, char **av);
int	is_valid(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int parse(int ac, char **av, t_data *d);
void	ft_eat(t_data *d, int time, int i);
// void ft_putnbr(int n);
int ft_atoi(char *s);
size_t get_time();
int	set_end(t_data *d);
int set_usleep(size_t t);
// int set_usleep(size_t t, t_data *d);

#endif

//a thread is a component of a process
//a process is a unit of resources, 
//while a thread is a unit of scheduling and execution
//multiple threads of a process may be executed concurrently 
//sharing resources such as memory
//the threads of a process share its executable code 
//and the values of its dynamically allocated variables 
//and non-thread-local global variables at any given time.
//Kernel threads do not own resources except for a stack, 
//a copy of the registers including the program counter, 
//and thread-local storage (if any), 
//and are thus relatively cheap to create and destroy
//context switching between threads in the same process 
//is faster than context switching between processes

//using threads, an application can operate using fewer 
//resources than it would need when using multiple processes

//Simplified sharing and communication of threads: unlike processes

//an illegal operation performed by a thread can crash the entire process

//Multithreading can be applied to one process to enable parallel execution