/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:52:04 by zkarman           #+#    #+#             */
/*   Updated: 2026/04/27 17:05:06 by karmanz          ###   ########.fr       */
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
    while (j < philo[0].data->number_of_philosophers)
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
        pthread_mutex_lock(&philo[0].data->write_lock);
        printf("All philosophers have eaten the necessary amount of times\n");
        pthread_mutex_unlock(&philo[0].data->write_lock);
        philo[0].data->is_dead = 1;
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
        while (i < philo[0].data->number_of_philosophers)
        {
            if (get_time() - philo[i].last_meal_time >= philo[0].data->time_to_die)
            {
                pthread_mutex_lock(&philo[0].data->write_lock);
                printf("%lld %d died\n", get_time() - philo[i].data->start_time, philo[i].id);
                pthread_mutex_unlock(&philo[0].data->write_lock);
                philo[0].data->is_dead = 1;
                return (NULL);
            }
            i++;
        }
        if (are_all_full(philo))
            return (NULL);
        usleep(1000);
    }
    return (NULL);
}

void    *philosopher_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    if (philo->data->number_of_philosophers == 1)
    {
        one_philo(philo);
        return (NULL);
    }
    while (1)
    {
        if (philo->data->is_dead)
            break ;
        is_eating(philo);
        is_sleeping(philo);
        is_thinking(philo);
    }
    return (NULL);
}

void    start_simulation(t_philo *philos, t_data *data)
{
    pthread_t   death_check;
    int i;
    
    data->start_time = get_time();
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_create(&philos[i].thread, NULL, &philosopher_routine, &philos[i]);
        i++;
    }
    pthread_create(&death_check, NULL, &check_for_deaths, philos);
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
    pthread_join(death_check, NULL);
    end_simulation(philos, data);
}