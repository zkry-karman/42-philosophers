/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:52:04 by zkarman           #+#    #+#             */
/*   Updated: 2026/05/06 15:33:40 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     are_all_full(t_philo *philo)
{
    int j;
    int all_full;

    if (philo[0].data->number_of_times_each_philosopher_must_eat < 1)
        return (0);
    j = 0;
    all_full = 1;
    while (j < philo[0].data->number_of_philo)
    {
        if (philo[j].meals_eaten < philo[0].data->number_of_times_each_philosopher_must_eat)
        {
            all_full = 0;
            break ;
        }
        j++;
    }
    if (all_full)
    {
        pthread_mutex_lock(&philo[0].data->dead_lock);
        philo[0].data->is_dead = 1;
        pthread_mutex_unlock(&philo[0].data->dead_lock);
        return (1);
    }
    return (0);
}

void    *check_for_deaths(void *arg)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)arg;
    while (1)
    {
        i = 0;
        while (i < philo[0].data->number_of_philo)
        {
            pthread_mutex_lock(&philo[0].data->dead_lock);
            if (get_time() - philo[i].last_meal_time >= philo[0].data->time_to_die)
            {
                philo[0].data->is_dead = 1;
                pthread_mutex_lock(&philo[0].data->write_lock);
                printf("%lld %d died\n", get_time() - philo[i].data->start_time, philo[i].id);
                pthread_mutex_unlock(&philo[0].data->write_lock);
                pthread_mutex_unlock(&philo[0].data->dead_lock);
                return (NULL);
            }
            pthread_mutex_unlock(&philo[0].data->dead_lock);
            i++;
        }
        if (are_all_full(philo))
            return (NULL);
        usleep(100);
    }
    return (NULL);
}

int     philo_died(t_philo *philo)
{
    int     death;
    pthread_mutex_lock(&philo->data->dead_lock);
    death = philo->data->is_dead;
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (death);
}

void    *philosopher_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->data->number_of_philo == 1)
    {
        one_philo(philo);
        return (NULL);
    }
    if (philo->id % 2 == 0)
        ft_usleep(philo->data->time_to_eat / 2);
    while (!philo_died(philo))
    {
        is_eating(philo);
        is_sleeping(philo);
        is_thinking(philo);
    }
    return (NULL);
}

void    start_simulation(t_philo *philos, t_data *data)
{
    int i;
    long long   current_time;
    
    current_time = get_time();
    data->start_time = current_time;
    i = 0;
    while (i < data->number_of_philo)
    {
        philos[i].last_meal_time = current_time;
        i++;
    }
    threading(philos, data);
    end_simulation(philos, data);
}