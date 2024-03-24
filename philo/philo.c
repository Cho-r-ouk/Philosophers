/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:40:16 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/02/01 18:29:35 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_putnbr(int n)
{
    if (n >= 0 && n <= 9)
    {
        n += '0';
        write(1, &n, 1);
        return ;
    }
    ft_putnbr(n / 10);
    ft_putnbr(n % 10);
}

void free_data(t_data *d)
{
	int i = 0;
	while (i < d->tab[0])
    { 
		pthread_mutex_destroy(&d->philo[i].fork_l);
        i++;
    }
	free(d->philo);
} 


size_t get_time()
{
    struct timeval t;

    if (gettimeofday(&t, NULL))
        return (write(2, "error getting time\n", 20), 0);
    return (t.tv_sec * 1000 + t.tv_usec / 1000);    
}

// int set_usleep(size_t t, t_data *d)
int set_usleep(size_t t)
{
    // (void)d;
    size_t time = get_time();

    while (get_time() < time + t)
    {
        // if (d->is_dead)
        //     exit(0) ;
        usleep(1);
    }
    return (0);
}

void set_message(char *s, int time, int id)
{
    pthread_mutex_t lock;

    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);
    printf("%d  %d  %s\n", time, id, s);
    // ft_putnbr(time);
    // write(1, "  ", 2);
    // ft_putnbr(id);
    // write(1, "  ", 2);
    // write(1, s, ft_strlen(s));
    pthread_mutex_unlock(&lock);
    pthread_mutex_destroy(&lock);
}

void *check_eat_count(void *p0)
{
    pthread_mutex_t lock;
    t_philo *p = (t_philo *)p0;
    pthread_mutex_init(&lock, NULL);
    while (!p->data->is_dead)
    {
        pthread_mutex_lock(&lock);
        if (p->data->tab[4] && p->eat_count == p->data->tab[4])
            p->data->is_dead = 1;
        // printf("%d  %d  %d\n", (int)get_time() - p->last_meal, p->data->tab[1], p->is_eating);
        if ((p->last_meal != p->data->start_time) && (int)get_time() - p->last_meal >= p->data->tab[1] && !p->is_eating)
        {
            // printf("--%d  %d\n", (int)get_time() - p->last_meal, p->data->tab[1]);
            p->data->is_dead = 1;
            set_message("died", get_time() - p->data->start_time, p->id);//philo is dead\n
            // exit(0);
        }
        pthread_mutex_unlock(&lock);
    }
    return (NULL);
}

void *set_action(void *p0)
{
    t_philo *p = (t_philo *)p0;
    pthread_mutex_t lock;
    int time;

    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);
    time = p->data->start_time;
    pthread_mutex_unlock(&lock);
    if (!(p->id % 2))
        usleep(p->data->tab[2]);
    while (1)//!p->data->is_dead
    {
        pthread_mutex_lock(&p->fork_l);
        set_message(" has taken a fork", get_time() - time, p->id);//left fork\n
        pthread_mutex_lock(p->fork_r);
        set_message(" has taken a fork", get_time() - time, p->id);//right fork\n
        set_message("is eating", get_time() - time, p->id);//philo is eating\n
        p->is_eating = 1;
        // if(set_usleep(p->data->tab[2], p->data))
        if(set_usleep(p->data->tab[2]))
            return (NULL);
        (p->eat_count)++;
        p->last_meal = get_time();
        pthread_mutex_unlock(&p->fork_l);
        pthread_mutex_unlock(p->fork_r);
        p->is_eating = 0;
        set_message("is sleeping", get_time() - time, p->id);//philo is sleeping\n
        // if(set_usleep(p->data->tab[3], p->data))
        if(set_usleep(p->data->tab[3]))
            return (NULL);
        set_message("is thinking", get_time() - time, p->id);//philo is thinking\n
        if (p->data->is_dead)
            break ;
    }
    pthread_mutex_destroy(&lock);
    return (NULL);
}

int set_fork(t_data *d)
{
    int i = 0;
    d->philo = (t_philo *)malloc(sizeof(t_philo) * (d->tab[0]));
    if (!d->philo)
        return (write(2, "malloc error\n", 14), 0);
    while (i < d->tab[0])
    {
        if (pthread_mutex_init(&d->philo[i].fork_l, NULL))
            return (write(2, "error creating lock\n", 21), 0);
        // usleep(1000);
        i++;
    }
    i = 0;
    while (i < d->tab[0])
    {
        d->philo[i].fork_r = &d->philo[(i + 1) % (d->tab[0])].fork_l;
        i++;
    }
    return (1);
}


int set_philo(t_data *d)
{
    int i = 0;
    pthread_t eat_count;

    if (!set_fork(d))
        return (0);
    d->start_time = get_time();
    d->is_dead = 0;
    while (i < d->tab[0])
    {
        d->philo[i].id = i + 1;
        d->philo[i].data = d;
        d->philo[i].eat_count = 0;
        d->philo[i].last_meal = d->start_time;
        i++;
    }
    i = 0;
    if (pthread_create(&eat_count, NULL, &check_eat_count, (void *)&d->philo[i]))
        return (write(2, "error creating thread\n", 23), 0);

    while (i < d->tab[0])
    {
        if (pthread_create(&d->philo[i].philo, NULL, &set_action, (void *)&d->philo[i]))
            return (write(2, "error creating thread\n", 23), 0);
        // set_usleep(1000);
        i++;
    }
    // d->start = 1;
    i = 0;
    while (i < d->tab[0])
    {
        // if (pthread_detach(d->philo[i].philo))
        if (pthread_join(d->philo[i].philo, NULL))
            return (write(2, "error joining thread\n", 22), 0);
        i++;
    }
    if (pthread_join(eat_count, NULL))
        return (1);
    // set_end(d);//, i
    free_data(d);
    return (1);
}

// void leak(){system("leaks philo");}

int main(int ac, char **av)
{
    // atexit(leak);
    t_data d = {0};

    if (parse(ac, av, &d))
        return (1);
    // d.full = d.tab[0];
    if (!set_philo(&d))
        return (1);
    // if (!set_fork(&d))
    //     return (1);
    return (0);
}