/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:29 by karmanz           #+#    #+#             */
/*   Updated: 2026/05/01 21:50:13 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_eating(t_philo *philo)
{
    if (philo_died(philo))
        return ;
    if (philo->id % 2 != 0)
        pthread_mutex_lock(philo->r_fork);
    else
        pthread_mutex_lock(philo->l_fork);
    print_timestamp(philo, "has taken a fork");
    if (philo->id % 2 != 0)
        pthread_mutex_lock(philo->l_fork);
    else
        pthread_mutex_lock(philo->r_fork);
    print_timestamp(philo, "has taken a fork");
    pthread_mutex_lock(&philo->data->dead_lock);
    philo->last_meal_time = get_time();
    pthread_mutex_unlock(&philo->data->dead_lock);
    print_timestamp(philo, "is eating");
    philo->meals_eaten++;
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}