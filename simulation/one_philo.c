/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmanz <karmanz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:14:54 by karmanz           #+#    #+#             */
/*   Updated: 2026/04/27 17:03:06 by karmanz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    one_philo(t_philo *philo)
{
    while (1)
    {
        if(philo->data->is_dead)
            return ;
        if(!pthread_mutex_lock(philo->r_fork))
        {
            pthread_mutex_lock(&philo->data->write_lock);
            printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
            pthread_mutex_unlock(&philo->data->write_lock);
        }
    }
}