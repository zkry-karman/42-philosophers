/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:04:50 by karmanz           #+#    #+#             */
/*   Updated: 2026/03/21 15:37:18 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

    long long   start_time;
    int is_dead;
    pthread_mutex_t *forks;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
}   t_data;

typedef struct s_philo
{
    pthread_t   thread;
    int id;
    int last_meal_time;
    int meals_eaten;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    t_data  *data;
}   t_philo;

t_data  *initialize_data(char **args);
t_philo *initialize_philos(t_data *data);

#endif