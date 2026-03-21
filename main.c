/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:02:08 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/21 15:37:18 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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