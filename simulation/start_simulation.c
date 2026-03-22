/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:52:04 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/22 21:31:51 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
        //need to create is_eating
        is_eating(philo);
        //Need to create is_sleeping
        is_sleeping(philo);
        //need to create is_thinking
        is_thinking(philo);
    }
    return (NULL);
}

void    start_simulation(t_philo *philos, t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->number_of_philosophers)
    {
        //need to create philosopher_routine function
        pthread_create(&philos[i].thread, NULL, &philosopher_routine, &philos[i]);
        i++;
    }
    i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}