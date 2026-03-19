/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:02:08 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/19 15:26:26 by karmanz          ###   ########.fr       */
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
        i++;
    }
    return (philos);
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
    
    //need to finish setting up data struct
    
    return (data);
}

int valid_arguments(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return(printf("%s\n", "Must have either 4 or 5 arguments"), 0);
    if (ft_atoi(av[1]) < 1)
        return(printf("%s\n", "Need at least 1 philosopher"), 0);
    if (ft_atoi(av[1]) > INT_MAX || ft_atoi(av[2]) > INT_MAX || ft_atoi(av[3]) > INT_MAX || ft_atoi(av[4]) > INT_MAX)
        return(printf("%s%d\n", "Parameters must be less than or equal to: " INT_MAX), 0);
    if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
        return(printf("%s%d\n", "Parameters must be greater than or equal to: " 0), 0);
    if(av[5] && (ft_atoi(av[5]) < 0 || ft_atoi(av[5]) > INT_MAX))
        return(printf("%s%d%s%d\n" "Parameters must be between " 0, "and " INT_MAX), 0);
    return (1);
}

int main(int ac, char **av)
{
    t_data  *data;
    t_philo *philos;
    
    if (!valid_arguments(ac, av))
        return (1);
    data = initialize_data(av);
    philos = initialize_philos(data);
}