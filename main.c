/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:02:08 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/17 13:48:06 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data  initialize_data(char **args)
{
    t_data  *data;
    
}

int valid_arguments(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return(printf("%s\n", "Must have either 4 or 5 arguments"), 0);
    if (av[1] < 1)
        return(printf("%s\n", "Need at least 1 philosopher"), 0);
    if (av[1] > INT_MAX || av[2] > INT_MAX || av[3] > INT_MAX || av[4] > INT_MAX)
        return(printf("%s%d\n", "Parameters must be less than or equal to: " INT_MAX), 0);
    if (av[2] < 0 || av[3] < 0 || av[4] < 0)
        return(printf("%s%d\n", "Parameters must be greater than or equal to: " 0), 0);
    if(av[5] && (av[5] < 0 || av[5] > INT_MAX))
        return(printf("%s%d%s%d\n" "Parameters must be between " 0, "and " INT_MAX), 0);
    return (1);
}

int main(int ac, char **av)
{
    t_data  *data;
    
    if (!valid_arguments(ac, av))
        return (1);
    data = initialize_data(av);
}