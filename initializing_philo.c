/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_philo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:15:19 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/21 15:37:18 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *initialize_philos(t_data *data)
{
    t_philo *philos;
    int i;

    philos = malloc(sizeof(t_philo) * data->number_of_philosophers);
    if (!philos)
        return (NULL);
    i = 0;
    while (i < data->number_of_philosophers)
    {
        philos[i].id = i + 1;
        philos[i].last_meal_time = get_time();
        philos[i].meals_eaten = 0;
        philos[i].data = data;
        philos[i].l_fork = &data->forks[i];
        philos[i].r_fork = &data->forks[(i + 1) % data->number_of_philosophers];
        i++;
    }
    return (philos);
}