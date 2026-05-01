/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:27:57 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/01 22:29:41 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    threading(t_philo *philos, t_data *data)
{
    pthread_t   death_check;
    int     i;

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
}