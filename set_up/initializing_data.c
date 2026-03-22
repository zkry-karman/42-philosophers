/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 15:13:09 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/22 21:29:58 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_forks(t_data *data)
{
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philosophers);
    if (!data->forks)
        return (0);
    i = 0;
    while (i < data->number_of_philosophers)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
            return (0);
        i++;
    }
    pthread_mutex_init(&data->write_lock, NULL);
    pthread_mutex_init(&data->dead_lock, NULL);
    return (1);
}

t_data  *initialize_data(char **args)
{
    t_data  *data;
    
    data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    data->number_of_philosophers = ft_atoi(args[1]);
    data->time_to_die = ft_atoi(args[2]);
    data->time_to_eat = ft_atoi(args[3]);
    data->time_to_sleep = ft_atoi(args[4]);
    if (args[5])
        data->number_of_times_each_philosopher_must_eat = ft_atoi(args[5]);
    else
        data->number_of_times_each_philosopher_must_eat = -1;
    data->is_dead = 0;
    
    //need to finish setting up data struct
    if (!init_forks(data))
        //free and exit;
    
    return (data);
}