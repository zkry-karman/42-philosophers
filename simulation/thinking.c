/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:13:57 by karmanz           #+#    #+#             */
/*   Updated: 2026/04/26 22:20:30 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    is_thinking(t_philo *philo)
{
    pthread_mutex_lock(philo->data.write_lock);
    printf("%lld %d is thinking", get_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(philo->data.write_lock);
}