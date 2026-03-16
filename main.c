/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarman <zkarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 14:02:08 by zkarman           #+#    #+#             */
/*   Updated: 2026/03/15 20:31:11 by zkarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_makenode(t_philo *philosophers, int i)
{
    t_philo *newnode;
    t_philo *lastnode;

    newnode = malloc(sizeof(t_philo));
    if (!newnode)
        return ;
    newnode->
}

t_philo *a_table(int ac, char **av)
{
    int i;
    int number_of_philosphers;
    t_philo *philosophers; 

    i = 1;
    number_of_philosphers = av[1];
    while (i < number_of_philosphers)
    {
        ft_makenode(philosophers, i);
        i++;
    }
}

int valid_arguments(int ac, char **av)
{
    if (ac < 5 || ac > 6)
        return(printf("%s\n", "Must have either 4 or 5 arguments"), 0);
    if (av[1] > INT_MAX || av[2] > INT_MAX || av[3] > INT_MAX || av[4] > INT_MAX)
        return(printf("%s%d\n", "Parameters must be less than or equal to: " INT_MAX), 0);
    if (av[1] < INT_MIN || av[2] < INT_MIN || av[3] < INT_MIN || av[4] < INT_MIN)
        return(printf("%s%d\n", "Parameters must be greater than or equal to: " INT_MIN), 0);
    if(av[5] && (av[5] < INT_MIN || av[5] > INT_MAX))
        return(printf("%s%d%s%d\n" "Parameters must be between " INT_MIN, "and " INT_MAX), 0);
    return (1);
}

int main(int ac, char **av)
{
    t_philo *philos;

    if (!valid_arguments(ac, av))
        return (1);
    philos = a_table(ac, av);
}