/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:52:04 by zkarman           #+#    #+#             */
/*   Updated: 2026/04/26 23:14:47 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *check_for_deaths(void *arg)
{
    
}

void    *philosopher_routine(void *arg)
{
    t_philo *philo;

    philp = (t_philo *)arg;

    if (philos->data->number_of_philosophers == 1)
        //Need to create one philo case
        return (one_philo(philo));

    while (1)
    {
        if (philo->data.is_dead)
            break ;
        is_eating(philo);
        is_sleeping(philo);
        is_thinking(philo);
    }
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
    pthread_create(&death_check, NULL, &check_for_deaths, NULL)
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}