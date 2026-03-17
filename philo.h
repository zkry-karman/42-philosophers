/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:04:50 by karmanz           #+#    #+#             */
/*   Updated: 2026/03/17 13:47:15 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_data
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

    long long   start_time;
    int is_dead;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
}   t_data;

int main(int ac, char **av)

#endif