/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:02:08 by zkarman           #+#    #+#             */
/*   Updated: 2026/04/27 15:50:23 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int valid_arguments(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return(printf("Must have either 4 or 5 arguments\n"), 0);
    if (ft_atoi(av[1]) < 1)
        return(printf("Need at least 1 philosopher\n"), 0);
    if (ft_atoi(av[1]) > INT_MAX || ft_atoi(av[2]) > INT_MAX || ft_atoi(av[3]) > INT_MAX || ft_atoi(av[4]) > INT_MAX)
        return(printf("Parameters must be less than or equal to: %d\n", INT_MAX), 0);
    if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
        return(printf("Parameters must be greater than or equal to: %d\n", 0), 0);
    if(av[5] && (ft_atoi(av[5]) < 0 || ft_atoi(av[5]) > INT_MAX))
        return(printf("Parameters must be between 0 and %d\n", INT_MAX), 0);
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
    if (!data || !philos)
        end_simulation(philos, data);
    else
        start_simulation(philos, data);
    return (0);
}