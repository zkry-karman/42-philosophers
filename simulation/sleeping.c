/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:46 by karmanz           #+#    #+#             */
/*   Updated: 2026/04/27 17:03:56 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->write_lock);
    printf("%lld %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->write_lock);
    ft_usleep(philo->data->time_to_sleep);
}