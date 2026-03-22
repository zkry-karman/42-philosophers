/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:29 by karmanz           #+#    #+#             */
/*   Updated: 2026/03/22 23:28:21 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_eating(t_philo *philo)
{
    //Need to add timestamps for all the printfs
    pthread_mutex_lock(philo->l_fork);
    pthread_mutex_lock(philo->data.write_lock);
    printf("%d has taken a fork", philo->id);
    pthread_mutex_unlock(philo->data.write_lock);
    pthread_mutex_lock(philo->r_fork);
    pthread_mutex_lock(philo->data.write_lock);
    printf("%d has taken a fork", philo->id)
    pthread_mutex_unlock(philo->data.write_lock);
    pthread_mutex_lock(philo->data.write_lock);
    printf("%s is eating", philo->id);
    pthread_mutex_unlock(philo->data.write_lock);
    //eat for time_to_eat seconds
    
    
}