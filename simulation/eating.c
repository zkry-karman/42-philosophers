/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:29 by karmanz           #+#    #+#             */
/*   Updated: 2026/04/27 17:02:03 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_eating(t_philo *philo)
{
    if (philo->id % 2 != 0)
        pthread_mutex_lock(philo->r_fork);
    else
        pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->write_lock);
    if (philo->id % 2 != 0)
        pthread_mutex_lock(philo->l_fork);
    else
        pthread_mutex_lock(philo->r_fork);
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->write_lock);
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%lld %d is eating\n", get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->write_lock);
    philo->last_meal_time = get_time();
    philo->meals_eaten++;
    ft_usleep(philo->data->time_to_eat);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}