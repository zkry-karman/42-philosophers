/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:52:04 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/21 21:50:55 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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