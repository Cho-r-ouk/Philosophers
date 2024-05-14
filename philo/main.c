/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmasnaou <cmasnaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:37:20 by cmasnaou          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:17 by cmasnaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void leak(){system("leaks philo");}

int main(int ac, char **av)
{
    //atexit(leak);
    t_data d = {0};

    if (parse(ac, av, &d))
        return (1);
    // int i = 0;
    // while (i < 5)
    // {
    //     printf("%ld\n", d.tab[i]);
    //     i++;
    // }
    if (d.tab[0] == 0)
        return (0);
    if (d.tab[0] == 1)
    {
        printf("0\t1\thas taken a fork\n");
        usleep(d.tab[1] * 1000);
        printf("%-6ld\t%-3d\tdied\n", d.tab[1], 1);
        return (0);
    }
    if (!set_philo(&d))
        return (1);
    return (0);
}